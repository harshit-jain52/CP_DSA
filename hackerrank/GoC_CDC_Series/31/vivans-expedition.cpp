#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,x; cin >> n >> x;
    int ta[n],tb[n];
    for(int i=0;i<n;i++) cin >> ta[i];
    for(int i=0;i<n;i++) cin >> tb[i];
    
    ll dp[n][2];
    dp[0][0]=ta[0], dp[0][1]=x+tb[0];
    
    for(int i=1;i<n;i++){
        dp[i][0] = ta[i]+min(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = tb[i]+min(dp[i-1][1],dp[i-1][0]+x);
    }
    
    for(int i=0;i<n;i++) cout << min(dp[i][0],dp[i][1])<<" ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}