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
	    ll a[n];
	    for(ll i=0;i<n;i++)
	        cin >> a[i];
	    ll ans=0;
	    for(ll i=1;i<n;i++){
	        ans += abs(a[i]-a[i-1])-1;
	    }
	    cout << ans << endl;
	}
	return 0;
}
