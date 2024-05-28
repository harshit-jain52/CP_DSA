#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+1;
const int LOG = 20;

struct Edge{
    int u,v;
    ll w;
    int id;

    Edge(){w=0;}

    bool operator <(Edge &other){
        return w < other.w;
    }
};

int par[N], set_size[N];
vector<pair<int,ll>>g[N];
int up[N][LOG], depth[N];
ll dp[N][LOG];

void make(int v){
    par[v]=v;
    set_size[v]=1;
}

int find(int v){
    if(v==par[v]) return v;
    return par[v]=find(par[v]);
}

void Union(int u, int v){
    u=find(u);v=find(v);
    if(u==v) return;

    if(set_size[u]<set_size[v]) swap(u,v);

    par[v]=u;
    set_size[u]+=set_size[v];
}

void dfs(int v, int pp, int dep, ll wt){
    depth[v]=dep;
    up[v][0]=pp;
    dp[v][0]=wt;

    for(int i=1;i<LOG;i++){
        up[v][i] = up[up[v][i-1]][i-1];
        dp[v][i] = max(dp[v][i-1],dp[up[v][i-1]][i-1]);
    }

    for(auto ch: g[v]){
        if(ch.first==pp) continue;
        dfs(ch.first,v,dep+1,ch.second);
    }
}

ll pathMax(int u, int v){
    if(depth[u]<depth[v]) swap(u,v);

    ll ans = 0;
    for(int i=LOG-1;i>=0;i--){
        if((depth[u]-depth[v])&(1<<i)){
            ans = max(ans,dp[u][i]);
            u = up[u][i];
        }
    }

    if(u==v) return ans;

    for(int i=LOG-1;i>=0;i--){
        if(up[u][i] != up[v][i]){
            ans = max({ans,dp[u][i],dp[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }

    ans = max({ans,dp[u][0],dp[v][0]});
    return ans;
}

int main()
{
    FASTIO
    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++) make(i);

    vector<Edge> e(m);
    for(int i=0;i<m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].id=i;
    }

    ll mst_wt = 0;
    sort(e.begin(),e.end());

    for(int i=0;i<m;i++){
        int u = e[i].u, v = e[i].v;
        ll wt = e[i].w;
        if(find(u)==find(v)) continue;

        Union(u,v);
        mst_wt += wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }

    dfs(1,0,0,0);

    ll ans[m];

    for(int i=0;i<m;i++) ans[e[i].id] = mst_wt - pathMax(e[i].u,e[i].v) + e[i].w;

    for(int i=0;i<m;i++) cout << ans[i]<<endl;

}