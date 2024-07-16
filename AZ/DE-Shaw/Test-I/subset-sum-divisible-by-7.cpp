#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
vector<vector<int>>dp;
vector<int>arr;
int n;

int func(int idx, int mod){
    if(idx==n) return (mod==0);
    if(dp[idx][mod]!=-1) return dp[idx][mod];

    int ans = func(idx+1,mod);;
    ans += func(idx+1,(mod+arr[idx])%7);
    ans %= M;

    return dp[idx][mod]=ans;
}

void solve(){
    cin >> n;
    arr.resize(n);
    dp.assign(n+1,vector<int>(7,-1));

    for(int i=0;i<n;i++) cin >> arr[i];
    
    cout << func(0,0) << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}