#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    
    for(int len=1;len<=n;len++){
        for(int i=0;i<n;i++){
            int j = len+i-1;
            if(j>=n) break;
            
            if(len==1){
                dp[i][j]=true;
                continue;
            }
            if(len==2){
                dp[i][j] = (s[i]==s[j]);
                continue;
            }
            dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
        }
    }
    
    vector<int>pref(n,1),suff(n,1);
    for(int i=1;i<n;i++){
        int len=0;
        for(int j=i;j>=0;j--) if(dp[j][i]) len = (i-j+1);
        pref[i] = max(pref[i-1],len);
    }
    for(int i=n-2;i>=0;i--){
        int len=0;
        for(int j=i;j<n;j++) if(dp[i][j]) len = (j-i+1);
        suff[i]=max(suff[i+1],len);
    }
    
    int ans=0;
    for(int i=0;i<n-1;i++) ans = max(ans,pref[i]*suff[i+1]);
    cout << ans << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}