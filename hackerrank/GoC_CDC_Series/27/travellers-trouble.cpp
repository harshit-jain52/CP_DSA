#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
const ll INF = 1e16;
#define F first
#define S second

vector<ll> dijkstra(int src, int n, vector<vector<pii>>&g){
    vector<ll>dist(n+1,INF);
    dist[src]=0;
    priority_queue<pii>pq;
    pq.push({0,src});
    
    while(!pq.empty()){
        int v = pq.top().S;
        pq.pop();
        
        for(auto ch: g[v]){
            if(dist[ch.F]>dist[v]+ch.S){
                dist[ch.F]=dist[v]+ch.S;
                pq.push({-dist[ch.F],ch.F});
            }
        }
    }
    
    return dist;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<pii>>g(n+1);
    vector<vector<pii>>rg(n+1);
    
    int x,y; cin >> x >> y;
    vector<pii>edges(m);
    for(int i=0;i<m;i++){
        int u,v,w;cin >> u >> v >> w;
        g[u].push_back({v,w});
        rg[v].push_back({u,w});
        edges[i]={u,v};
    }
    
    vector<ll> dist1 = dijkstra(x,n,g);
    vector<ll> dist2 = dijkstra(y,n,rg);
    
    ll orig = dist1[y];
    
    for(int i=0;i<m;i++){
        int u = edges[i].F, v = edges[i].S;
        ll tmp = min({orig,dist1[u] + dist2[v],dist1[v]+dist2[u]});
        cout << ((tmp<INF)?tmp:-1)<<" ";
    }
    cout << '\n';
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}