#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

class DSU{
    int par[N];
    int set_size[N];

public:
    DSU(int n){
        for(int i=1;i<=n;i++){
            par[i]=i;
            set_size[i]=1;
        }
    }

    int Find(int v){
        if(v==par[v]) return v;
        return par[v]=Find(par[v]);
    }

    void Union(int u, int v){
        u = Find(u); v= Find(v);
        if(u==v) return;

        if(set_size[u]<set_size[v]) swap(u,v);
        par[v]=u;
        set_size[u]+=set_size[v];
    }

    bool isMerged(int u, int v){
        return (Find(u)==Find(v));
    }
};

int main()
{
    FASTIO
    int n,q; cin >> n>>q;
    
    vector<DSU>uf;
    for(int i=0;i<=10;i++){
        uf.push_back(DSU(n));
    }

    int tot = 0;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        tot += c;

        for(int i=c;i<=10;i++) uf[i].Union(a,b);
    }
    
    while(q--){
        int u,v,w;
        cin >> u >> v >> w;

        int first=10;
        for(int i=10;i>=1;i--){
            if(!uf[i].isMerged(u,v)) break;
            first=i;
        }

        if(first>w){
            for(int i=w;i<=10;i++) uf[i].Union(u,v);
            tot += (w-first);
        }

        cout << tot << endl;
    }
}