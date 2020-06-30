#include<iostream>
#include<queue>
#include<fstream>
#define size 30
using namespace std;
int man[size][size], woman[size][size], n;
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
    
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            cout << man[a][b] << " ";
        }
        cout <<endl;
    }
         cout <<endl;
     for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            cout << woman[a][b] << " ";
        }
        cout <<endl;
    }

}

int main(){
    Input();
    return 0;
}
