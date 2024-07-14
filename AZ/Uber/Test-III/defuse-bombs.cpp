#include <bits/stdc++.h>
using namespace std;

int dp[31][2][2];

int func(int bit, int L, int R, bool lo, bool hi, int X){
    if(bit<0) return 0;
    if(dp[bit][lo][hi]!=-1) return dp[bit][lo][hi];

    int loLim = ((lo)?((L>>bit)&1):0);
    int hiLim = ((hi)?((R>>bit)&1):1);

    int ans = 0;
    for(int d=loLim;d<=hiLim;d++){
        int add=0;
        if(((X>>bit)&1)!=d) add += (1<<bit);
        ans = max(ans,add+func(bit-1,L,R,lo&&(d==loLim),hi&&(d==hiLim),X));
    }

    return dp[bit][lo][hi] = ans;
}

int main(){
    int n; cin >> n;
    int x[n],l[n],r[n];
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<n;i++) cin >> r[i];

    for(int i=0;i<n;i++){
        memset(dp,-1,sizeof(dp));
        cout << func(30,l[i],r[i],1,1,x[i]) << " ";
    }
}