#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define REP(i,n) for(int i=0; i<n; i++)
const int INF = 1e9+1;

vector<pii>moves={{1,0},{0,1},{-1,0},{0,-1}};

void solve(){
    int n,d;
    cin >> n >> d;
    vector<vector<int>>dist(n,vector<int>(n,INF));
    queue<pii>q;
    
    REP(i,n) REP(j,n){
        char c; cin >> c;
        if(c=='#'){
            dist[i][j]=0;
            q.push({i,j});
        }
    }
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int x = cur.F, y = cur.S;
        
        for(auto [dx,dy]: moves){
            int nx = x+dx, ny = y+dy;
            if(nx>=0 && ny>=0 && nx<n && ny<n){
                if(dist[nx][ny]>dist[x][y]+1){
                    dist[nx][ny] = dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    REP(i,n){
        REP(j,n){
            cout << ((dist[i][j]<=d)?'x':'.');
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
}