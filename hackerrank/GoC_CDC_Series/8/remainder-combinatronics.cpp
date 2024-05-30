#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
const int N = 1e5+1;
int dp[N][13];
int n;
string s;

int func(int i, int r){
    if(i==n) return (r==5);
    if(dp[i][r]!=-1) return dp[i][r];
      
    int ct = 0;
    if(s[i]!='?') ct = func(i+1,(r*10 + (s[i]-'0'))%13);
    else for(int d=0;d<=9;d++) ct = (ct+func(i+1,(r*10 + d)%13))%M;
    
    return dp[i][r]=ct;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin >> s;
    n = s.size();
    cout << func(0,0);
}