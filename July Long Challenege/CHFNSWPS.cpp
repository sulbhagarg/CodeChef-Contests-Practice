#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ulli;
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    ll n;
	    cin >> n;
	    vector<ll> a(n), b(n);
	    map<ll,ll> ma,mb;
	    map<ll,ll> m;
	    ll min_a=INT_MAX;
	    ll min_b=INT_MAX;
	    int flag=0;
	    for(ll i=0;i<n;i++){
	        cin >> a[i];
	        ma[a[i]]++;
	        m[a[i]]++;
	        min_a=min(a[i], min_a);
	    }
	    for(ll i=0;i<n;i++){
	        cin >> b[i];
	        mb[b[i]]++;
	        m[b[i]]++;
	        min_b=min(b[i], min_b);
	    }
	    for(auto it:m){
	        if(it.second%2){
	            flag=1;
	            break;
	        }
	    }
	    if(flag==1) {
	        cout << "-1\n";
	        continue;
	    }
	    vector<ll> temp;
	    sort(a.begin(), a.end());
	    sort(b.begin(), b.end());
	    for(ll i=0;i<n;i++){
	        if(mb.find(a[i])==mb.end()) {
                temp.push_back(a[i]);
                i++;
	        } else if(ma[a[i]]!=mb[a[i]]) {
	            ll x=abs(ma[a[i]]-mb[a[i]])/2;
	            while(x--)
                    temp.push_back(a[i]);
                while(i<n-1 && a[i]==a[i+1])
                    i++;
	        }
	    }
	    for(ll i=0;i<n;i++){
	        if(ma.find(b[i])==ma.end()) {
	            temp.push_back(b[i]);
	            i++;
	        }
	    }
        sort(temp.begin(), temp.end());
        ll ans=0;
        ll i=0;
        ll s = temp.size();
        for(i=0;i<s/2;i++){
            if(temp[i]<2*min_a && temp[i]<2*min_b)
                ans+=temp[i];
            else
                ans+=min(2*min_a, 2*min_b);
        }
        cout << ans << "\n";
	}
	return 0;
}
