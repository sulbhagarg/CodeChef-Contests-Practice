#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ulli;
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin >> t;
	while(t--){
	    ll n,x;
	    cin >> n >> x;
	    vector<ll> v;
	    ll temp;
	    for(ll i=0;i<n;i++){
	        cin >> temp;
	        v.push_back(temp);
	    }
	    sort(v.begin(),v.end());
	    ll i=n-1;
	    while(i>0){
	        if(v[i-1]*2>=v[i] || v[i-1]*2>=x){
	            i--;
	        } else {
	            break;
	        }
	    }
	    ll idx=i,ans=0;
	    while(i<n){
	        if(x<v[i]){
	            x*=2;
	            ans++;
	            continue;
	        }
	        ans++;
	        x=v[i];
	        v[i]=0;
	        i++;
	        x*=2;
	    }
	    ans+=idx;
	    cout << ans << endl;
	}
	return 0;
}
