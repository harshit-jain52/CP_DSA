#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<char>>grid(n,vector<char>(m));
    REP(i,n) REP(j,m) cin >> grid[i][j];

    int x1,y1,x2,y2; cin >> x1>>y1>>x2>>y2;
    x1--;y1--;x2--;y2--;

    const int INF = 1e7;
    vector<vector<int>>dist(n,vector<int>(m,INF));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    dist[x1][y1]=0;
    vis[x1][y1]=true;

    queue<pii>q;
    q.push({x1,y1});

    while(!q.empty()){
        auto v = q.front();
        q.pop();
        int x = v.F, y = v.S;

        int lim = k;
        for(int i=x+1; lim>0 && i<n && grid[i][y]!='#' && dist[i][y]>=(dist[x][y]+1); i++, lim--){
            if(vis[i][y]) continue;
            dist[i][y]=dist[x][y]+1;
            q.push({i,y});
            vis[i][y]=true;
        }

        lim=k;
        for(int i=x-1; lim>0 && i>=0 && grid[i][y]!='#' && dist[i][y]>=(dist[x][y]+1); i--, lim--){
            if(vis[i][y]) continue;
            dist[i][y]=dist[x][y]+1;
            q.push({i,y});
            vis[i][y]=true;
        }

        lim=k;
        for(int j=y-1; lim>0 && j>=0 && grid[x][j]!='#' && dist[x][j]>=(dist[x][y]+1); j--, lim--){
            if(vis[x][j]) continue;
            dist[x][j]=dist[x][y]+1;
            q.push({x,j});
            vis[x][j]=true;
        }

        lim=k;
        for(int j=y+1; lim>0 && j<m && grid[x][j]!='#' && dist[x][j]>=(dist[x][y]+1); j++, lim--){
            if(vis[x][j]) continue;
            dist[x][j]=dist[x][y]+1;
            q.push({x,j});
            vis[x][j]=true;
        }
    }

    cout << ((dist[x2][y2]<INF)?dist[x2][y2]:-1);
}