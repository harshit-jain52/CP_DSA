#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+5;
const int LOG = 20;

vector<int>g[N];
int up[N][LOG];
int depth[N];

void dfs(int v, int pp, int dep){
    up[v][0]=pp;
    depth[v]=dep;

    for(int i=1;i<LOG;i++) up[v][i] = up[up[v][i-1]][i-1];

    for(int ch: g[v]){
        if(ch!=pp) dfs(ch,v,dep+1);
    }
}

int LCA(int u, int v){
    if(depth[u]<depth[v]) swap(u,v);

    for(int i=LOG-1;i>=0;i--){
        if((depth[u]-depth[v])&(1<<i)) u = up[u][i];
    }

    if(u==v) return u;

    for(int i=LOG-1;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int kthA(int u, int k){
    for(int i=LOG-1;i>=0;i--){
        if(k&(1<<i)) u = up[u][i];
    }
    return u;
}

int main()
{
    FASTIO
    int n,q;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0,0);

    cin >> q;
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;

        int lc = LCA(a,b);
        if(c>=(depth[a]+depth[b]-2*depth[lc])) cout << b;
        else if(c>=(depth[a]-depth[lc])) cout << kthA(b,(depth[b]-depth[lc])-(c-(depth[a]-depth[lc])));
        else cout << kthA(a,c);

        cout << endl;
    }

}