#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+5;

vector<int>g[N];
bool spots[N], go[N];
int dp[N];

void dfs(int v, int pp){
    dp[v]=0;
    go[v] = spots[v];
    for(int ch: g[v]){
        if(ch==pp) continue;
        dfs(ch,v);
        go[v] |= go[ch];
        if(go[ch]) dp[v] += (1+dp[ch]);
    }
}

int main(){
    int n,k,x;
    cin >> n >> k >> x;
    
    for(int i=0;i<k;i++){
        int con; cin >> con;
        spots[con]=true;
    }
    
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(x,0);
    cout << 2*dp[x];
}