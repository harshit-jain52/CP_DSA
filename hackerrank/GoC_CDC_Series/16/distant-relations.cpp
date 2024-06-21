#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int par[26], sz[26];

void make(){
    for(int i=0;i<26;i++){
        par[i]=i;
        sz[i]=1;
    }
}

int Find(int v){
    return ((par[v]==v)?v:par[v]=Find(par[v]));
}

void Union(int u, int v){
    u = Find(u); v = Find(v);
    if(u==v) return;
    
    if(sz[u]<sz[v]) swap(u,v);
    par[v]=u;
    sz[u]+=sz[v];
}

int main(){
    make();
    int n,m; cin >> n >> m;
    while(m--){
        char c1,c2;
        cin >> c1 >> c2;
        Union(c1-'a',c2-'a');
    }
    
    int dp[n+1][26];
    for(int j=0;j<26;j++) dp[1][j]=1;
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<26;j++){
            dp[i][j] = dp[i-1][j];
            for(int k=0;k<26;k++){
                if(Find(j)==Find(k)) continue;
                dp[i][j] += dp[i-1][k];
                dp[i][j]%=M;
            }
        }
    }
    
    int ans = 0;
    for(int j=0;j<26;j++){
        ans += dp[n][j];
        ans %= M;
    }
    
    cout << ans;
}