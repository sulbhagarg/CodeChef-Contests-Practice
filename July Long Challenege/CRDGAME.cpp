#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    ll n;
	    cin >> n;
	    ll point_a=0,point_b=0;
	    while(n--){
	        ll a,b;
	        cin >> a >> b;
	        ll t1=a,t2=b;
	        ll temp_a=0,temp_b=0;
	        while(t1){
	            temp_a+=t1%10;
	            t1/=10;
	        }
	        while(t2){
	            temp_b+=t2%10;
	            t2/=10;
	        }
	        if(temp_a==temp_b){
	            point_a++;
	            point_b++;
	        }
	        else if(temp_a>temp_b){
	            point_a++;
	        }
	        else{
	            point_b++;
	        }
	    }
	    if(point_a==point_b){
	        cout << "2 " << point_a << endl;
	    }
	    else if(point_a>point_b){
	        cout << "0 " << point_a << endl;
	    }
	    else{
	        cout << "1 " << point_b << endl;
	    }
	}
	return 0;
}
