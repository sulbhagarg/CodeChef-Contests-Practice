#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ulli;
using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,q;
	cin >> n >> q;
	vector<ll> h(n), a(n);
	for(ll i=0;i<n;i++){
	    cin >> h[i];
	}
	for(ll i=0;i<n;i++)
	    cin >> a[i];
	    
	stack<pair<ll,ll>> s;
	vector<ll> pathExistRightMap(n, -1),pathExistLeftMap(n, -1);
	map<pair<ll,ll>, ll> path;
	s.push(make_pair(h[n-1],n-1));
	pathExistRightMap[n-1]=-1;
	for(ll i=n-2;i>=0;i--){
	    while(!s.empty() && s.top().first<=h[i]) {
	        s.pop();
	    }
	    if(!s.empty()){
	        ll idx=s.top().second;
	        pathExistLeftMap[i]=idx;
	        path[make_pair(i,idx)]=a[i]+a[idx];
	    }
	    s.push(make_pair(h[i],i));
	}
	while(!s.empty())
	    s.pop();
	s.push(make_pair(h[0],0));
	for(ll i=1;i<n;i++){
	    while(!s.empty() && s.top().first<=h[i]) {
	        s.pop();
	    }
	    if(!s.empty()){
	        ll idx=s.top().second;
	        pathExistRightMap[i]=idx;
	        path[make_pair(i,idx)]=a[idx]+a[i];
	    }
	    s.push(make_pair(h[i],i));
	}
	while(!s.empty())
	    s.pop();
// 	for(ll i=0;i<n;i++){
// 	    cout << i << " " << pathExistLeftMap[i] << " " << pathExistRightMap[i] << endl;
// 	}
	ll t,b,c,change=0;
	for(ll i=0;i<q;i++){
	    cin >> t >> b >> c;
	    ll ans=0;
	    if(t==1) {
	        a[b-1]=c;
	        change=1;
	    } else if(change) {
	        if(b<c) {
	            b--;
	            c--;
	            swap(b,c);
	            int flag=0;
	            while(b>=c){
	                ans+=a[b];
	                if(b==c)
	                    break;
	                b=pathExistRightMap[b];
	                if(b==-1 || b<c){
	                    flag=1;
	                    break;
	                }
	            }
	            if(flag) {
	                cout << "-1" << "\n";
	            } else {
	                cout << ans << "\n";
	            }
	        } else if(b>c) {
	            b--;
	            c--;
	            swap(b,c);
	            int flag=0;
	            while(b<=c) {
	                ans+=a[b];
	                if(b==c)
	                    break;
	                b=pathExistLeftMap[b];
	                if(b==-1 || b>c){
	                    flag=1;
	                    break;
	                }
	            }
	            if(flag) {
	                cout << "-1" << "\n";
	            } else {
	                cout << ans << "\n";
	            }
	        } else {
	            cout << a[b-1] << "\n";
	        }
	    } else {
	        if(b<c) {
	            if(path.find(make_pair(c-1, b-1))!=path.end()){
	                cout << path[make_pair(c-1,b-1)] << "\n";
	                continue;
	            }
	            b--;
	            c--;
	            swap(b,c);
	            ll temp=b;
	            int flag=0;
	            while(b>=c){
	                ans+=a[b];
	                path[make_pair(temp,b)]=ans;
	                if(b==c)
	                    break;
	                b=pathExistRightMap[b];
	                if(b==-1 || b<c){
	                    flag=1;
	                    break;
	                }
	            }
	            if(ans==0)
	                ans=-1;
	            if(flag) {
	                cout << "-1" << "\n";
	            } else {
	                cout << ans << "\n";
	            }
	        } else if(b>c) {
	            if(path.find(make_pair(c-1, b-1))!=path.end()){
	                cout << path[make_pair(c-1, b-1)] << "\n";
	                continue;
	            }
	            b--;
	            c--;
	            swap(b,c);
	            ll temp=b;
	            int flag=0;
	            while(b<=c) {
	                ans+=a[b];
	                path[make_pair(temp,b)]=ans;
	                if(b==c)
	                    break;
	                b=pathExistLeftMap[b];
	                if(b==-1 || b>c){
	                    flag=1;
	                    break;
	                }
	            }
	            if(ans==0)
	                ans=-1;
	            if(flag) {
	                cout << "-1" << "\n";
	            } else {
	                cout << ans << "\n";
	            }
	        } else {
	            cout << a[b-1] << "\n";
	        }
	    }
	}
	return 0;
}
