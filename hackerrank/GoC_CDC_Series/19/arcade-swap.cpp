#include <bits/stdc++.h>
using namespace std;
int dp[5000][5001];
int n, l[5000], r[5000];

int func(int i,int sum){
    if(i==n) return (sum==0);
    if(dp[i][sum]!=-1) return dp[i][sum];
    
    int ans = false;
    if(sum>=l[i]) ans |= func(i+1,sum-l[i]);
    if(sum>=r[i]) ans |= func(i+1,sum-r[i]);
    return dp[i][sum]=ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    int m; cin >> n >> m;
    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<n;i++) cin >> r[i];
    
    func(0,m);
    if(dp[0][m]){
        cout << "YES\n";
        int i=0, sum=m;
        while(i<n-1){
            if(sum>=l[i] && dp[i+1][sum-l[i]]){
                cout << '0';
                sum -= l[i];
            }
            else{
                cout << '1';
                sum -= r[i];
            }
            i++;
        }
        if(sum==l[i]) cout << '0';
        else cout << '1';
        cout << '\n';
    }

    else cout << "NO\n";
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}