#include <bits/stdc++.h>
using namespace std;
const int LOG=20;
typedef pair<int,int>pii;
#define F first
#define S second

struct node{
    int aa, oo, xx;
    node(){
        aa = (1<<20)-1;
        oo = xx = 0;
    }
};

node init(int val){
    node tmp;
    tmp.aa=tmp.oo=tmp.xx=val;
    return tmp;
}

node merge(node x, node y){
    node tmp;
    tmp.aa = x.aa&y.aa;
    tmp.oo = x.oo|y.oo;
    tmp.xx = x.xx^y.xx;

    return tmp;
}

vector<vector<pii>>g;
vector<int>dep;
vector<vector<int>>up;
vector<vector<node>>dp;

void dfs(int v, int pp, int val, int d){
    if(v!=1){
        up[v][0]=pp;
        dp[v][0]=init(val);
    }
    
    dep[v]=d;
    
    for(int i=1;i<LOG;i++){
        up[v][i] = up[up[v][i-1]][i-1];
        dp[v][i] = merge(dp[v][i-1],dp[up[v][i-1]][i-1]);
    }

    for(auto ch: g[v]) if(ch.F!=pp) dfs(ch.F,v,ch.S,d+1);
}

node query(int u, int v){
    if(dep[u]<dep[v]) swap(u,v);
    
    node ans;
    for(int i=LOG-1;i>=0;i--){
        if((dep[u]-dep[v])&(1<<i)){
            ans = merge(ans, dp[u][i]);
            u = up[u][i];
        }
    }
    
    if(u==v) return ans;

    for(int i=LOG-1;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            ans = merge(ans,dp[u][i]);
            ans = merge(ans,dp[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }
    
    ans = merge(ans,dp[u][0]);
    ans = merge(ans,dp[v][0]);
    return ans;
}

void solve(){
    int n,q; cin >> n >> q;
    g.assign(n+1,vector<pii>());
    dep.assign(n+1,0);
    up.assign(n+1,vector<int>(LOG,0));
    dp.assign(n+1,vector<node>(LOG,node()));
    
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    
    dfs(1,0,0,0);

    while(q--){
        int u, v; cin >> u >> v;
        node tmp = query(u,v);
        // cout << tmp.aa << " "<< tmp.oo <<" "<< tmp.xx << endl;
        cout << tmp.aa + tmp.oo + tmp.xx << endl;
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}