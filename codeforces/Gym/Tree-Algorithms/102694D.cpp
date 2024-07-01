#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+10;
const int LOG = 20;

int d[N], up[N][LOG], dp[N][LOG];
vector<pair<int,int>>g[N];

void dfs(int v, int pp, int dep, int w){
    d[v]=dep;
    up[v][0]=pp;
    dp[v][0]=w;

    for(int i=1;i<LOG;i++){
        up[v][i] = up[up[v][i-1]][i-1];
        dp[v][i] = min(dp[v][i-1],dp[up[v][i-1]][i-1]);
    }

    for(auto ch: g[v]) if(ch.F!=pp) dfs(ch.F,v,dep+1,ch.S);
}

int minPath(int u, int v){
    if(d[u]<d[v]) swap(u,v);

    int ans = INT_MAX;
    for(int i=LOG-1;i>=0;i--){
        if((d[u]-d[v])&(1<<i)){
            ans = min(ans, dp[u][i]);
            u = up[u][i];
        }
    }

    if(u==v) return ans;

    for(int i=LOG-1;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            ans = min({ans,dp[u][i],dp[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }

    ans = min({ans,dp[u][0],dp[v][0]});
    return ans;
}

int main()
{
    FASTIO
    int n,m; cin >> n >> m;
    for(int i=0;i<LOG;i++) dp[0][i]=INT_MAX;

    while(m--){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dfs(1,0,0,INT_MAX);

    int q; cin >> q;
    while(q--){
        int a,b; cin >> a >> b;
        cout << minPath(a,b) << endl;
    }
}