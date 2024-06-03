#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n,m;
    cin >> n >> m;
    vector<vector<char>>grid(n,vector<char>(m));
    REP(i,n) REP(j,m) cin >> grid[i][j];

    const int INF = 1e7;
    int dist[n][m][3];
    deque<pair<int,int>>q[3];

    REP(i,n) REP(j,m) REP(k,3){
        dist[i][j][k] = INF;
        if((grid[i][j]-'1') == k){
            dist[i][j][k]=0;
            q[k].push_back({i,j});
        }
    }

    vector<pair<int,int>>steps = {{0,1},{0,-1},{1,0},{-1,0}};

    REP(k,3){
        while(!q[k].empty()){
            auto v = q[k].front();
            q[k].pop_front();
            int x = v.F, y = v.S;

            for(auto [dx,dy]: steps){
                int nx = x+dx, ny = y+dy;
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#'){
                    if(grid[nx][ny]!='.'){
                        if(dist[nx][ny][k]>dist[x][y][k]){
                            dist[nx][ny][k]=dist[x][y][k];
                            q[k].push_front({nx,ny});
                        }
                    }
                    else{
                         if(dist[nx][ny][k]>dist[x][y][k]+1){
                            dist[nx][ny][k]=dist[x][y][k]+1;
                            q[k].push_back({nx,ny});
                        }   
                    }
                }
            }
        }
    }

    int ans = INF;
    REP(i,n) REP(j,m) ans = min(ans, dist[i][j][0]+dist[i][j][1]+dist[i][j][2]-2*(grid[i][j]=='.'));
    cout << ((ans<INF)?ans:-1);
}