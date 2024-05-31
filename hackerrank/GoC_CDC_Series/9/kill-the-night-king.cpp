#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;


int main(){    
    int h; cin >> h;
    vector<int>dp(h+1,1e9);

    dp[0]=0; dp[1]=1;

    for(int i=1;i<h;i++){
        dp[i+1] = min(dp[i+1],1+dp[i]);
        for(int j=2*i;j<=h && j<=i*1LL*i; j+=i){
            dp[j]=min(dp[j],1+dp[i]);
        }
    }

    cout << dp[h];
}