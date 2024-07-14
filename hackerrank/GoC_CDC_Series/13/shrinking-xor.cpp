#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    dp.assign(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j) dp[i][j]=a[i];
            else if(j==i+1) dp[i][j]=a[i]^a[j];
            else dp[i][j]=dp[i+1][j]^dp[i][j-1];
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i<n-1) dp[i][j]=max(dp[i][j],dp[i+1][j]);
            if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }

    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        l--; r--;
        cout << dp[l][r] << " ";
    }
}