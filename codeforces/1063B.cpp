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
    int n,m,r,c,llim,rlim;
    cin >> n >> m >> r >> c >> llim >> rlim;
    r--; c--;
    vector<vector<char>>grid(n,vector<char>(m));
    REP(i,n) REP(j,m) cin >> grid[i][j];

    const int INF = 1e9+1;

    vector<vector<int>>left(n,vector<int>(m,INF));
    left[r][c]=0;
    deque<pii>q;
    q.push_back({r,c});

    vector<pii> steps = {{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty()){
        auto v  = q.front();
        q.pop_front();
        int x = v.F, y = v.S;
        for(auto [dx,dy]: steps){
            int nx=x+dx,ny=y+dy;
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='.'){
                if(dy==-1){
                    if(left[nx][ny]>left[x][y]+1){
                        left[nx][ny] = left[x][y]+1;
                        q.push_back({nx,ny});
                    }   
                }
                else{
                    if(left[nx][ny]>left[x][y]){
                        left[nx][ny] = left[x][y];
                        q.push_front({nx,ny});
                    }
                }
            }
        }
    }

    int ct = 0;
    REP(i,n) REP(j,m) ct+=(left[i][j]<=llim && (j-c)+left[i][j]<=rlim);
    cout << ct;
}