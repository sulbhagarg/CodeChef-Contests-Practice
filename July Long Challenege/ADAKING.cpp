#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int k;
	    cin >> k;
	    char s[8][8];
	    int flag=1;
	    for(int i=0;i<8;i++){
	        for(int j=0;j<8;j++){
	            if(k>0){
	                s[i][j]='.';
	                k--;
	            }
	            else if(i>0){
	                if(s[i-1][j]=='.' && flag==1){
	                    s[i][j]='X';
	                }
	                else if(s[i-1][j]=='X' && flag==1){
	                    s[i][j]='X';
	                    flag=-1;
	                }
	                else{
	                    s[i][j]='.';
	                   // flag=0;
	                }
	            }
	            else{
	                s[i][j]='X';
	            }
	        }
	    }
	    s[0][0]='O';
	    for(int i=0;i<8;i++){
	        for(int j=0;j<8;j++){
	            cout << s[i][j];
	        }
	        cout << endl;
	    }
	}
	return 0;
}
