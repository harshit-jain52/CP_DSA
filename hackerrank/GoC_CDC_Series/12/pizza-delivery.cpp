#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
typedef pair<int,int> pii;
#define F first
#define S second

void solve(){
    int n,m; cin >> n >> m;
    int a,b,c,d; cin >> a >> b >> c >> d;
    
    char g[n+1][m+1];
    
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> g[i][j];
    
    vector<vector<int>>dist(n+1,vector<int>(m+1,INF));
    deque<pii>dq;
    dq.push_back({a,b});
    dist[a][b]=0;
    
    
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        
        int x = cur.F, y = cur.S;
        int nx,ny;
        
        nx=x-1,ny=y; // up
        if(nx>0){
            if(g[x][y]=='U'){
                if(dist[nx][ny]>dist[x][y]){
                    dist[nx][ny] = dist[x][y];
                    dq.push_front({nx,ny});
                }
            }
            else if(dist[nx][ny]>dist[x][y]+1){
                dist[nx][ny]=dist[x][y]+1;
                dq.push_back({nx,ny});
            }
        }
        
        nx=x+1,ny=y; // down
        if(nx<=n){
            if(g[x][y]=='D'){
                if(dist[nx][ny]>dist[x][y]){
                    dist[nx][ny] = dist[x][y];
                    dq.push_front({nx,ny});
                }
            }
            else if(dist[nx][ny]>dist[x][y]+1){
                dist[nx][ny]=dist[x][y]+1;
                dq.push_back({nx,ny});
            }
        }
        
        nx=x,ny=y-1; // left
        if(ny>0){
            if(g[x][y]=='L'){
                if(dist[nx][ny]>dist[x][y]){
                    dist[nx][ny] = dist[x][y];
                    dq.push_front({nx,ny});
                }
            }
            else if(dist[nx][ny]>dist[x][y]+1){
                dist[nx][ny]=dist[x][y]+1;
                dq.push_back({nx,ny});
            }
        }
        
        nx=x,ny=y+1; // right
        if(ny<=m){
            if(g[x][y]=='R'){
                if(dist[nx][ny]>dist[x][y]){
                    dist[nx][ny] = dist[x][y];
                    dq.push_front({nx,ny});
                }
            }
            else if(dist[nx][ny]>dist[x][y]+1){
                dist[nx][ny]=dist[x][y]+1;
                dq.push_back({nx,ny});
            }
        }
    }
    
    cout << dist[c][d]<<endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}