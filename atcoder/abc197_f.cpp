#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int INF = 1e9;
#define F first
#define S second

int main()
{
    FASTIO
    int n,m; cin >> n >> m;
    vector<vector<bool>>edge(n+1,vector<bool>(n+1,false));
    vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
    vector<vector<pair<int,char>>>g(n+1);

    while(m--){
        int a,b; char c;
        cin >> a >> b >> c;
        edge[a][b]=edge[b][a]=true;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    dist[1][n]=0;
    queue<pair<int,int>>q;
    q.push({1,n});

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int x = cur.F, y = cur.S;

        for(auto nx: g[x]){
            for(auto ny: g[y]){
                if(nx.S == ny.S){
                    if(dist[nx.F][ny.F]>dist[x][y]+1){
                        dist[nx.F][ny.F]=dist[x][y]+1;
                        q.push({nx.F,ny.F});
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) ans = min(ans,2*dist[i][j]);
            else if(edge[i][j]) ans = min(ans,2*dist[i][j]+1);
        }
    }

    cout << ((ans<INF)?ans:-1);
}