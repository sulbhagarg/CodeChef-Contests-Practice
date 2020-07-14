#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ulli;
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	    ll n;
	    cin >> n;
	    map<ll,ll> mx,my;
	    ll x,y;
	    for(ll i=0;i<4*n-1;i++){
	        cin >> x >> y;
	        mx[x]++;
	        my[y]++;
	    }
	    for(auto it=mx.begin();it!=mx.end();it++){
	        if(it->second&1){
	            cout << it->first << " ";
	            break;
	        }
	    }
	    for(auto it=my.begin();it!=my.end();it++){
	        if(it->second&1){
	            cout << it->first << "\n";
	            break;
	        }
	    }
	}
	return 0;
}
