#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+1;

int main(){
    vector<int>ct(N,0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        ct[a]++;
    }
    
    vector<ll>dp(N);
    dp[0]=0; dp[1]=ct[1];
    
    ll premx=0, ans = dp[1];
    for(int i=2;i<N;i++){
        premx = max(premx,dp[i-2]);
        dp[i] = premx + i*1LL*ct[i];
        ans = max(ans,dp[i]);
    }
    
    cout << ans;
}