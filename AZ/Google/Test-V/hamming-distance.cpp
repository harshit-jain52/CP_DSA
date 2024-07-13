#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>vis;

void dfs(int v, int id){
    vis[v]=id;
    for(int ch:g[v]) if(!vis[ch]) dfs(ch,id);
}

void solve(){
    int n,m; cin >> n >> m;
    g.assign(n+1,vector<int>());
    vis.assign(n+1,0);

    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    while(m--){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int id=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,id++);
    }

    vector<vector<int>>comp(id);
    for(int i=1;i<=n;i++) comp[vis[i]].push_back(i);

    int ans = 0;
    for(int c=1;c<id;c++){
        map<int,int>anums;
        int sz = comp[c].size();
        for(int i=0;i<sz;i++) anums[a[comp[c][i]]]++;
        for(int i=0;i<sz;i++){
            int idx = comp[c][i];
            if(anums[b[idx]]) anums[b[idx]]--;
            else ans++;
        }
    }

    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}