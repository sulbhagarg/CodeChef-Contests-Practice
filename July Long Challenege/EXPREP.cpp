#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ulli;
using namespace std;

ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x%m + m) % m;
    return res;
}
 
ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
	// your code goes here
	ll t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    ll w[26];
	    for(int i=0;i<26;i++)
	        cin >> w[i];
	    ll n = s.length();
	    ll d = modInverse(2, 998244353);
	    ll den = (n%998244353 * (n+1)%998244353)%998244353;
	    den = (den%998244353 * d%998244353)%998244353;
	    map<string,ll> weightMap,powerMap,countMap;
	    for(ll i=0;i<n;i++){
	        string temp="";
	        ll weight=0;
	        for(ll j=i;j<n;j++){
	            temp+=s[j];
	            weight=(weight%998244353 + w[s[j]-'a']%998244353)%998244353;
	            if(countMap.find(temp)==countMap.end())
	                countMap[temp]=0;
	            countMap[temp]=(countMap[temp]%998244353 + 1%998244353)%998244353;
	            if(weightMap.find(temp)==weightMap.end()){
	                weightMap[temp]=weight%998244353;
	            }
	            if(powerMap.find(temp)==powerMap.end()){
	                powerMap[temp]=weight%998244353;
	                if(temp.length()>1){
    	                string temp1="";
    	                int temp_len=temp.length();
    	                map<string,int> localMap;
        	            for(ll k=0;k<temp_len-1;k++){
        	                temp1+=temp[k];
        	                string temp2 = temp.substr(0,temp_len-k-1)+temp1;
        	                if(temp2==temp){
        	                   // cout << temp1 << " " << temp << " " << k << endl;
        	                    if(localMap.find(temp.substr(0,temp_len-k-1))==localMap.end()){
        	                        powerMap[temp]=(powerMap[temp]%998244353 + weightMap[temp.substr(0,temp_len-k-1)]%998244353)%998244353;
        	                        localMap[temp.substr(0,temp_len-k-1)]=1;
        	                    }
        	                   // break;
        	                }
        	            }
    	            }
	            }
	        }
	    }
	    
	    ll num=0;
	    for(auto it: powerMap){
	        num=(num%998244353 + (countMap[it.first]%998244353 * it.second%998244353)%998244353)%998244353;
	    }
	    ll ans = modInverse(den, 998244353);
        ans = (ans%998244353 * num%998244353)%998244353;
        cout << ans << "\n";
	}
	return 0;
}
