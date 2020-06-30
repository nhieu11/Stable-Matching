#include<iostream>
#include<fstream>
#include<queue>
#define size 30
using namespace std;
//Bùi Ngọc Hiếu 20187319
int man[size][size], woman[size][size]; // Thứ tự yêu thích 
int n,stableMarriage[size][2]; 
int love[size];// Người mà hiện tại w đang hẹn hò love[w] = m, Nếu đang trong độc thân love[w] = -1
int inspect[size]; // duyệt danh sách yêu thích của m
int rank[size][size]; // thứ hạng

void Input(){
    int i;
	ifstream listin("input.txt");
	if (listin.is_open()) {
		listin >> n;
		for(int a=1; a<=n ; a++) { 
            for (int b=1; b<=n;b++){
                listin >> i;
			    man[a][b]=i;
		    }
        }
		
        for(int a=1; a<=n ; a++) { 
            for (int b=1; b<=n;b++){
                listin >> i;
			    woman[a][b]=i;
		    }
        }
		listin.close();
	} else cout << "file not found"; 
}

void Solution(){
	queue<int> freeMan; // Danh sách những người m độc thân
	for (int i = 1; i <= n; i++){
		love[i] = -1;             // Khởi tạo tất cả độc thân
	}
	
	  // Lưu thứ tự ưu tiên vào mảng hai chiều
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                rank[i][woman[i][j]] = j; 
            }
        }

	  //Đẩy freeMan vào queue
			for (int i = 1; i <= n; i++){
				freeMan.push(i);
			}

		// Biến tạm
        int m, w; //current man, woman

		while(!freeMan.empty()){  //Khi trong queue vẫn có freeMan 
			m = freeMan.front();  //Truy vấn người đầu tiên trong queue 
			w = man[m][inspect[m]++];  //Duyệt w trong danh sách yêu thích của man

			// Nếu w đang độc thân
			 if (love[w] == -1) {   
                love[w] = m;   // m và w hẹn hò
                freeMan.pop();
            } else {			//w đang hẹn hò với m'
                // nếu w thích m hơn m'
                if (rank[w][m] < rank[w][love[w]]) {
                    // chia tay với m' và hẹn hò cùng m
                    freeMan.pop();   //pop m vừa hẹn hò mới ra khỏi queue
                    freeMan.push(love[w]);  //Đẩy m' bị đá vào queue
                    love[w] = m;			//m mới và w hẹn hò
                }
            }
		}

        for (int i = 1; i <= n; i++) {	//Gán kết quả vào mảng 2 chiều 
            stableMarriage[i][1] = love[i];	
            stableMarriage[i][2] = i;
        }

}

void Output(){
	 for(int i=1; i<=n ;i++){
		 for (int j=1; j<=2; j++){
			 cout << stableMarriage[i][j] << " ";
		 }
		 cout << endl;
	}
}

int main(){
    Input();
	Solution();
	Output();
    return 0;
}
