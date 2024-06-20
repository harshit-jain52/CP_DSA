#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int N = 1e6;
ll dp[N+1][2];

int main(){
    FASTIO
    memset(dp,0,sizeof(dp));
    dp[0][0]=dp[0][1]=1;
    
    for(int i=1;i<=N;i++){
        if(i>=2){
            dp[i][0] += dp[i-2][1];
            dp[i][1] += dp[i-2][1];
        }
        dp[i][0] += dp[i-1][0];
    }
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n][0] << endl;
    }
}