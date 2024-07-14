#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.size();

    if(n==1){
        cout << 0 << endl;
        return;
    }

    string t = s+s;
    vector<vector<int>>dp(2*n+1,vector<int>(2,0));
    int ans = INT_MAX;
    for(int i=1;i<=2*n;i++){
        dp[i][0] = (t[i-1]!='w')+dp[i-1][1];
        dp[i][1] = (t[i-1]!='b')+dp[i-1][0];

        if(i>n){
            int ans0=dp[i-1][0],ans1=dp[i-1][1];

            if(n&1){
                ans0 -= dp[i-n-1][1];
                ans1 -= dp[i-n-1][0];
            }
            else{
                ans0 -= dp[i-n-1][0];
                ans1 -= dp[i-n-1][1];
            }

            ans = min({ans,ans0,ans1});
        }
    }

    cout << ans << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}