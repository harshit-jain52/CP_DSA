#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n,m,k;
    cin >> n >> m >> k;
    vector<string>maze(n);
    for(int i=0;i<n;i++) cin >> maze[i];

    int s=0;
    pair<int,int>start={-1,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]=='.'){
                s++;
                if(start.F==-1) start = {i,j};            
            }
        }
    }

    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<pair<int,int>> steps = {{1,0},{0,1},{-1,0},{0,-1}};


    auto check = [&](int x, int y)->bool{
        if(x<0 || y<0 || x>=n || y>=m) return false;
        if(maze[x][y]=='#' || vis[x][y]) return false;
        return true;
    };

    queue<pair<int,int>>q;
    q.push(start);

    while(!q.empty() && s>k){
        auto cur = q.front();
        q.pop();
        if(vis[cur.F][cur.S]) continue;

        vis[cur.F][cur.S]=true;
        // cout << cur.F << " "<<cur.S<<" "<<s<<endl;
        s--;

        for(auto [dx,dy]:steps){
            int nx=cur.F+dx,ny=cur.S+dy;
            if(check(nx,ny)) q.push(make_pair(nx,ny));
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]=='#') cout << '#';
            else if((maze[i][j]=='.') && vis[i][j]) cout << '.';
            else cout << 'X';
        }
        cout << endl;
    }
}