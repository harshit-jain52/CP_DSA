#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e4+4;
const int INF = 1e8;
#define F first
#define S second

vector<int> dijkstra(int src, int n, vector<vector<pii>>&g){
    vector<int>dist(n+1,INF);
    dist[src]=0;
    priority_queue<pii>pq;
    pq.push({0,src});
    
    while(!pq.empty()){
        auto cur = pq.top().S;
        pq.pop();
        
        for(auto ch: g[cur]){
            if(dist[ch.F]>dist[cur]+ch.S){
                dist[ch.F] = dist[cur]+ch.S;
                pq.push({-dist[ch.F],ch.F});
            }
        }
    }
    
    return dist;
}

int main(){
    int n,m; cin >> n >> m;
    int s,d; cin >> s >> d;
    vector<vector<pii>>g(n+1),rg(n+1);

    while(m--){
        int u,v,t;
        cin >> u >> v >> t;
        g[u].push_back({v,t});
        rg[v].push_back({u,t});
    }
    
    vector<int>dist1 = dijkstra(s,n,g);
    vector<int>dist2 = dijkstra(d,n,rg);
    
    int maxd=-1,mind=INT_MAX;
    for(int i=1;i<=n;i++) {
        maxd = max(maxd,dist1[i]+dist2[i]+1);
        mind = min(mind,dist1[i]+dist2[i]+1);
    }
    
    cout << ((maxd>=INF)?-1:mind);
}