#include <bits/stdc++.h>
using namespace std;

int dp[101];

int func(int n){
    if(n<=1) return 0;
    if(dp[n]!=-1) return dp[n];
    
    int ans = 0;
    if(n>=2) ans |= !func(n-2);
    if(n>=3) ans |= !func(n-3);
    if(n>=5) ans |= !func(n-5);
    
    return dp[n]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(func(n)) cout <<"First";
        else cout <<"Second";
        cout << endl;
    }
}