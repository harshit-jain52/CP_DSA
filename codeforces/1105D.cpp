#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i=0; i<n; i++)
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e9+7;
queue<pair<pii,pii>>q;
char grid[1001][1001];

int main()
{
    FASTIO
    int n,m,p;
    cin >> n >> m >> p;

    int s[p+1];
    for(int i=1;i<=p;i++) cin >> s[i];
    
    vector<vector<pii>>start(p+1);
    queue<pair<pii,int>>q[p+1];

    REP(i,n) REP(j,m){
        cin >> grid[i][j];
        if(grid[i][j]<='9' && grid[i][j]>='1') q[grid[i][j]-'0'].push({{i,j},s[grid[i][j]-'0']});
    }

    vector<pii>moves = {{1,0},{0,1},{-1,0},{0,-1}};

    while(1){
        bool done = true;
        for(int i=1;i<=p;i++){
            queue<pair<pii,int>>tmp;
            while(!q[i].empty()){
                done = false;
                tmp.push(q[i].front());
                q[i].pop();
            }

            while(!tmp.empty()){
                auto curr = tmp.front();
                tmp.pop();
                int x = curr.F.F, y= curr.F.S, ss = curr.S;
                if(ss==0){
                    q[i].push({{x,y},s[i]});
                    continue;
                }
                for(auto [dx,dy]: moves){
                    int nx=x+dx, ny = y+dy;
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='.'){
                        grid[nx][ny]=('0'+i);
                        tmp.push({{nx,ny},ss-1});
                    }
                }
            }
        }
        if(done) break;
    }
    

    vector<int>ct(p+1,0);
    REP(i,n) REP(j,m) if(grid[i][j]<='9' && grid[i][j]>='1') ct[grid[i][j]-'0']++;

    for(int i=1;i<=p;i++) cout << ct[i]<<" ";
    
}