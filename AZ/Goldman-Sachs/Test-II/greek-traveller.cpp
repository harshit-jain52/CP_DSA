#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>tin,lo;
int timer, numBR;

void dfs(int v, int par){
    tin[v]=lo[v]=++timer;

    for(int ch: g[v]){
        if(ch==par) continue;
        
        if(!tin[ch]){
            dfs(ch,v);
            if(tin[v]<lo[ch]) numBR++;

            lo[v]=min(lo[v],lo[ch]);
        }
        else lo[v]=min(lo[v],tin[ch]);
    }
}

void reset(int n){
    g.assign(n+1,vector<int>());
    tin.assign(n+1,0);
    lo.assign(n+1,0);
    timer=1;
    numBR=0;
}

void solve(){
    int n,m; cin >> n >> m;
    reset(n);

    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!tin[i]) dfs(i,0);
    }

    cout << numBR+1 << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}