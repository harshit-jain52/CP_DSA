#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const ll INF = 1e17;
#define F first
#define S second

void solve(){
    int n,m,s,t; cin >> n >> m >> s >> t;
    vector<vector<ll>>edge(n+1,vector<ll>(n+1,INF));
    vector<vector<ll>>dist(n+1,vector<ll>(n+1,INF));
    vector<vector<pair<int,pair<ll,char>>>>g(n+1);

    while(m--){
        int a,b; char c; ll w;
        cin >> a >> b >> w >> c;
        edge[b][a]=edge[a][b]=min(edge[a][b],w);
        g[a].push_back({b,{w,c}});
        g[b].push_back({a,{w,c}});
    }

    dist[s][t]=0;
    priority_queue<pair<ll,pair<int,int>>>pq;
    pq.push({0,{s,t}});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int x = cur.S.F, y = cur.S.S;

        for(auto nx: g[x]){
            for(auto ny: g[y]){
                if(nx.S.S == ny.S.S){
                    if(dist[nx.F][ny.F]>dist[x][y]+(nx.S.F+ny.S.F)){
                        dist[nx.F][ny.F]=dist[x][y]+(nx.S.F+ny.S.F);
                        pq.push({-dist[nx.F][ny.F],{nx.F,ny.F}});
                    }
                }
            }
        }
    }

    ll ans = INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) ans = min(ans,dist[i][j]);
            else ans = min(ans,dist[i][j]+edge[i][j]);
        }
    }

    cout << ((ans<INF)?ans:-1) << endl;
}

int main()
{
    FASTIO
    int t; cin >> t;
    while(t--) solve();
}