#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second

void solve(){
    int n; ll k;
    cin >> n >> k;
    
    vector<pair<ll,int>>c(n);
    for(int i=0;i<n;i++){
        cin >> c[i].F;
        c[i].S = n-i;
    }
    sort(c.begin(),c.end());
    
    ll tot = 0;
    for(int i=0;i<n;i++){
        ll ct = min(k/c[i].F,1ll*c[i].S);
        k -= ct*c[i].F;
        tot += ct;
    }
    
    cout << tot << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}