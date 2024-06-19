#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n+1],b[n+1];
    int apos[n+1];
    
    for(int i=1;i<=n;i++){
        cin >> a[i];
        apos[a[i]]=i;
    }
    
    for(int i=1;i<=n;i++){
        cin >> b[i];
        b[i]=apos[b[i]];
    }
    
    vector<int>dp(n+1,0);
    
    int len=0;
    for(int i=1;i<=n;i++){
        dp[b[i]] = dp[b[i]-1]+1;
        len=max(len,dp[b[i]]);
    }
    cout << (n-len);
}