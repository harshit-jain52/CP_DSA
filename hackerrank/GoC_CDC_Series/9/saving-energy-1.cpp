#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e15;

void solve(){
    int n; cin >> n;
    ll dp[n][2];
    for(int j=0;j<n;j++) cin >> dp[j][0];
    
    for(int i=1;i<n;i++){
        int idx=i&1;
        ll pref[n],suff[n];
        pref[0]=dp[0][idx^1]; suff[n-1]=dp[n-1][idx^1]-(n-1);
        for(int j=1;j<n;j++){
            pref[j] = max(pref[j-1],dp[j][idx^1]+j);
            suff[n-1-j]=max(suff[n-j],dp[n-1-j][idx^1]-(n-1-j));
        }
        for(int j=0;j<n;j++){
            ll a; cin >> a;
            dp[j][idx] = a+max(pref[j]-j,suff[j]+j);
        }
    }
    
    ll ans = -INF;
    for(int j=0;j<n;j++) ans = max(ans,dp[j][(n-1)&1]);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
}