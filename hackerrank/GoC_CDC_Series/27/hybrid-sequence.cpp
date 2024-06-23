#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1001][1001];

void solve(){
    int n,m; cin >> n >> m;
    int a[n+1], b[m+1];
    
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int j=1;j<=m;j++) cin >> b[j];
    
    int mina[n+1], maxa[n+1], minb[m+1], maxb[m+1];
    mina[0]=minb[0]=INT_MAX;
    maxa[0]=maxb[0]=INT_MIN;
    dp[0][0]=0;
    
    for(int i=1;i<=n;i++){
        mina[i]=min(a[i],mina[i-1]);
        maxa[i]=max(a[i],maxa[i-1]);
        dp[i][0]=maxa[i]-mina[i]+dp[i-1][0];
    }
    
    for(int j=1;j<=m;j++){
        minb[j]=min(b[j],minb[j-1]);
        maxb[j]=max(b[j],maxb[j-1]);
        dp[0][j]=maxb[j]-minb[j]+dp[0][j-1];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int mn=min(mina[i],minb[j]);
            int mx=max(maxa[i],maxb[j]);
            
            dp[i][j]=mx-mn+max(dp[i][j-1],dp[i-1][j]);
        }
    }
    
    cout << dp[n][m] << '\n';
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}