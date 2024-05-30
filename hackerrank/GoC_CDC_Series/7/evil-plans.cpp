#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> pii;
const int INF = 1e9;

int main(){
    int n,m,q,x;
    cin >> n >> m >> q >> x;
    
    vector<vector<int>>dist(n,vector<int>(m,INF));
    queue<pii>qu;
    while(q--){
        int x,y;
        cin >> x >> y;
        x--;y--;
        dist[x][y]=0;
        qu.push({x,y});
    }
    
    vector<pii> moves={{1,0},{0,1},{-1,0},{0,-1}};
    
    while(!qu.empty()){
        auto cur = qu.front();
        qu.pop();
        int x =cur.F, y=cur.S;
        for(auto [dx,dy]: moves){
            int nx=x+dx,ny=y+dy;
            if(nx>=0 && ny>=0 && nx<n && ny<m && dist[nx][ny]>1+dist[x][y]){
                dist[nx][ny]=1+dist[x][y];
                qu.push({nx,ny});
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << (dist[i][j]<=x)<<" ";
        }
        cout << endl;
    }
}
