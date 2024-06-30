#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;
const int INF = 2e9+2;

struct Edge{
    int a,b;
    ll w;

    Edge(){}
    bool operator<(Edge other){
        return w < other.w;
    }
};

struct DSU{
    vector<int>par;
    vector<int>sz;

    DSU(int n=1){
        par.assign(n+1,0);
        sz.assign(n+1,1);
        for(int i=1;i<=n;i++) par[i]=i;
    }

    int Find(int v){
        return ((par[v]==v)?v:par[v]=Find(par[v]));
    }

    void Union(int u, int v){
        u = Find(u), v = Find(v);
        if(u==v) return;

        if(sz[u]<sz[v]) swap(u,v);
        sz[u]+=sz[v];
        par[v]=u;
    }
};

int main()
{
    FASTIO
    int n,m; cin >> n >> m;

    vector<Edge>eg(m);

    for(int i=0;i<m;i++) cin >> eg[i].a >> eg[i].b >> eg[i].w;
    sort(eg.begin(),eg.end());

    ll ans = INF;
    for(int i=0;i<m;i++){
        ll mn = eg[i].w;
        DSU g(n);
        for(int j=i;j<m;j++){
            if(g.Find(eg[j].a)==g.Find(eg[j].b)) continue;            
            g.Union(eg[j].a,eg[j].b);

            if(g.sz[g.Find(1)]==n){
                ans = min(ans,eg[j].w-mn);
                break;
            }

        }
    }

    if(ans<INF) cout << "YES\n"<<ans;
    else cout << "NO\n";
}