#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int p[n+1]; for(int i=1;i<=n;i++) cin >> p[i];
    
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++) dp[i][0] = dp[0][i] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=i) dp[i][j]=max(dp[i][j],p[i]+dp[i][j-i]);
        }
    }
    
    cout << dp[n][n];
}