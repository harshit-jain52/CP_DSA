#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
const int LOG = 20;

vector<int>g[N];
int depth[N], subsz[N], up[N][LOG];

void dfs(int v, int pp, int dep){
    depth[v]=dep;
    subsz[v]=1;
    up[v][0]=pp;

    for(int i=1;i<LOG;i++) up[v][i] = up[up[v][i-1]][i-1];

    for(int ch: g[v]){
        if(ch==pp) continue;
        dfs(ch,v,dep+1);
        subsz[v] += subsz[ch];
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
    int n,m;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0,0);

    cin>>m;
    while(m--){
        int x,y;
        cin >> x >> y;
        int lc = LCA(x,y);

        if(depth[x]==depth[y]){
            int dep = depth[x]-depth[lc];
            int bef1 = kthA(x,dep-1);
            int bef2 = kthA(y,dep-1);

            cout << n-(subsz[bef1]+subsz[bef2])<<endl;
        }
        else{
            if(depth[x]<depth[y]) swap(x,y);

            int diff = depth[x] + depth[y] - 2*depth[lc];
            if(diff&1) cout << 0 << endl;
            else{
                int before = kthA(x,diff/2 - 1);
                int spot = up[before][0];
                cout << subsz[spot]-subsz[before]<<endl;
            }
        }
    }
}