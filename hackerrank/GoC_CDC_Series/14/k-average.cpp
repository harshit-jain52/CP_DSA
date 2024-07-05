#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,k; cin >> n >> k;
    map<ll,int>mp;
    mp[0]=1;
    
    ll ans = 0;
    ll pref = 0;
    
    for(int i=0;i<n;i++){
        ll a; cin >> a;
        pref += (a-k);
        ans += mp[pref];
        mp[pref]++;
    }
    
    cout << ans << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}