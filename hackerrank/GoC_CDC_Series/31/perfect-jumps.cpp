#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
vector<vector<int>>dist;
const int INF = 1e7;
void solve(){
    int n,m,x,y,d;
    cin >> n >> m >> x >> y >> d;
    
    if(x>n || y>m){
        cout << -1 << endl;
        return;
    }
    
    dist.assign(n+1,vector<int>(m+1,INF));
    vector<pii>moves;
    for(int i=0;i<=d;i++){
        int sq = d*d - i*i;
        int j = sqrt(sq);
        if(j*j == sq) moves.push_back({i,j});
    }
    
    dist[0][0]=0;
    queue<pii>q;
    q.push({0,0});
    
    auto check = [&](int nx, int ny){
        return (nx>=0 && ny>=0 && nx<=n && ny<=m);
    };
    
    while(!q.empty()){
        if(dist[x][y]<INF) break;
        
        int cx = q.front().F, cy = q.front().S;
        q.pop();
        
        for(auto [dx,dy]: moves){
            if(check(cx+dx,cy+dy) && dist[cx+dx][cy+dy]>dist[cx][cy]+1){
                dist[cx+dx][cy+dy]=dist[cx][cy]+1;
                q.push({cx+dx,cy+dy});
            }
            if(check(cx-dx,cy+dy) && dist[cx-dx][cy+dy]>dist[cx][cy]+1){
                dist[cx-dx][cy+dy]=dist[cx][cy]+1;
                q.push({cx-dx,cy+dy});
            }
            if(check(cx+dx,cy-dy) && dist[cx+dx][cy-dy]>dist[cx][cy]+1){
                dist[cx+dx][cy-dy]=dist[cx][cy]+1;
                q.push({cx+dx,cy-dy});
            }
            if(check(cx-dx,cy-dy) && dist[cx-dx][cy-dy]>dist[cx][cy]+1){
                dist[cx-dx][cy-dy]=dist[cx][cy]+1;
                q.push({cx-dx,cy-dy});
            }
        }
    }
    
    cout << ((dist[x][y]<INF)?dist[x][y]:-1)<<endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}