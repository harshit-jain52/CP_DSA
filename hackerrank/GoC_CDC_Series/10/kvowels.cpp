#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*1LL*a)%M;
        a = (a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n,k; cin >> n >> k;
    if(k==0){
        cout << binpow(21,n) << endl;
        return;
    }
    
    int dp[n+1][2];
    dp[0][0] = 1, dp[0][1] = 0;
    int pref=5;
    int pow5k=binpow(5,k);
    
    for(int i=1;i<=n;i++){        
        dp[i][0] = (21*1LL*(dp[i-1][0]+dp[i-1][1]))%M;
        dp[i][1] = pref;
        if(i>=k) pref = (pref - (pow5k*1LL*dp[i-k][0])%M + M)%M;
        pref = ((pref+dp[i][0])*5LL)%M;
    }
    
    // for(int i=0;i<=n;i++) cout << dp[i][0]<<" "<<    dp[i][1]<<endl;
    cout << (dp[n][0]+dp[n][1])%M << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}