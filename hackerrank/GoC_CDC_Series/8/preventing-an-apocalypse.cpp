#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2][3];

int main(){
    int n; cin >> n;    
    int idx=0;
    for(int i=0;i<n;i++){
        idx = i&1;
        int q,w,e; cin >> q >> w >> e;
        dp[idx][0] = q+min(dp[idx^1][1],dp[idx^1][2]);
        dp[idx][1] = w+min(dp[idx^1][0],dp[idx^1][2]);
        dp[idx][2] = e+min(dp[idx^1][1],dp[idx^1][0]);
    }
    
    cout << min({dp[idx][0],dp[idx][1],dp[idx][2]});
}