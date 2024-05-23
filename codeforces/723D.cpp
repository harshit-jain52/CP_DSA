#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i=0; i < n; i++)
typedef long long ll;
const int M = 1e9+7;
vector<vector<char>> grid;
vector<vector<int>>vis;
int n, m;

inline bool check(int x, int y){
    return (x>=0 && y>=0 && x<n && y<m && grid[x][y]=='.' && vis[x][y]==0); 
}

void dfs(int x, int y, int cp){
    vis[x][y] = cp;
    if(check(x+1,y)) dfs(x+1,y,cp);
    if(check(x,y+1)) dfs(x,y+1,cp);
    if(check(x-1,y)) dfs(x-1,y,cp);
    if(check(x,y-1)) dfs(x,y-1,cp);
}

int main()
{
    FASTIO

    int k;
    cin >> n >> m >> k;
    vis.resize(n,vector<int>(m,0));
    grid.resize(n,vector<char>(m));

    REP(i,n) REP(j,m) cin >> grid[i][j];

    // eliminating border lakes
    REP(i,n) REP(j,m) if(check(i,j) && (i==0 || i==n-1 || j==0 || j==m-1)) dfs(i,j,-1);

    int cp=0;
    REP(i,n) REP(j,m) if(check(i,j)) dfs(i,j,++cp);

    // REP(i,n){
    //     REP(j,m) cout << vis[i][j];
    //     cout << endl;
    // }

    vector<int>ct(cp+1,0);
    REP(i,n) REP(j,m) if(vis[i][j]>0) ct[vis[i][j]]++;

    vector<pair<int,int>>vec;
    for(int i=1;i<=cp;i++)  vec.push_back({ct[i],i});

    sort(vec.begin(),vec.end());
    
    int chng=0;
    for(int c=0;c<(cp-k);c++){
        int num = vec[c].second;
        chng += vec[c].first;
        REP(i,n) REP(j,m) if(vis[i][j]==num) grid[i][j]='*';
    }

    cout << chng << endl;
    REP(i,n){
        REP(j,m) cout << grid[i][j];
        cout << endl;
    }
}