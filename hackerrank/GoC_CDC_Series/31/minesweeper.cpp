#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second

char grid[101][101];
int vis[101][101];
int n,m;

bool check(int x, int y){
    return (x>=0 && y>=0 && x<n && y<m && grid[x][y]=='1');
}

vector<pii> moves = {{0,1},{1,0},{0,-1},{-1,0}};

int dfs(int x, int y, int k){
    if(k==0){
        if(x==0 && y==0) return 0;
        else return -100000;
    }
    
    int leaf = (vis[x][y]==0);
    vis[x][y]++;

    int ct = leaf+dfs(x,y,k-1);
    for(auto [dx,dy]: moves){
        int nx = x+dx, ny = y+dy;
        if(check(nx,ny)) ct = max(ct,leaf+dfs(nx,ny,k-1));
    }
    vis[x][y]--;
    return ct;
}

int main(){
    int x;
    cin >> n >> m >> x;
    
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> grid[i][j];
    cout << dfs(0,0,x);
}