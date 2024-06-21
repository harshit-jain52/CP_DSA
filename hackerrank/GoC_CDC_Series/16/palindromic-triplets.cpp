#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

bool dp[1001][1001];

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n<3){
        cout << 0 << endl;
        return;
    }

    for(int len=1;len<=n;len++){
        for(int i=0;i<n;i++){
            int j = i+len-1;
            if(i>j) break;
            
            if(len==1) dp[i][j]=true;
            else if(len==2) dp[i][j] = (s[i]==s[j]);
            else dp[i][j] = ((s[i]==s[j]) && dp[i+1][j-1]);
        }
    }
    vector<int>pref(n,0);
    pref[0]=1;
    for(int i=1;i<n;i++){
        pref[i]+=pref[i-1];
        pref[i]%=M;
        
        for(int j=0;j<=i;j++){
            pref[i]+=dp[j][i];
            pref[i]%=M;
        }
    }
    
    vector<int>suff(n,0);
    suff[n-1]=1;
    for(int i=n-2;i>=0;i--){
        suff[i]+=suff[i+1];
        suff[i]%=M;
        for(int j=n-1;j>=i;j--){
            suff[i]+=dp[i][j];
            suff[i]%=M;
        }
    }
    
    int ans = 0;
    for(int i=1;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            if(dp[i][j]){
                ans += (pref[i-1]*1LL*suff[j+1])%M;
                ans %= M;
            }
        }
    }
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}