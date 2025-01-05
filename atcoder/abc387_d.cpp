#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<n;i++)
const int M = 1e9+7;
const int N = 1005;
const int INF = 1e8;

ostream& operator<<(ostream& os, const pii& p) {
    os << "(" << p.F << ", " << p.S << ")";
    return os;
}

vector<vector<char>>grid(N,vector<char>(N));
vector<vector<vector<int>>>dist(N,vector<vector<int>>(N,vector<int>(2,INF)));
vector<pii> dir = {{0,1},{0,-1},{1,0},{-1,0}};

int main()
{
	FASTIO
	int h,w; cin >> h >> w;
	pii s,g;
	REP(i,h) REP(j,w){
		cin >> grid[i][j];
		if(grid[i][j]=='S') s = {i,j};
		else if(grid[i][j]=='G') g = {i,j};
	}

	// cout << s << g;
	queue<tuple<int,int,int>>q;
	dist[s.F][s.S][0]=0;
	dist[s.F][s.S][1]=0;
	q.push({s.F,s.S,0});
	q.push({s.F,s.S,1});

	while(!q.empty()){
		auto [x,y,z]=q.front();
		q.pop();

		for(auto [dx,dy]: dir){
			if(abs(dx)==z) continue;
			int nx=x+dx, ny=y+dy, nz=1^z;
			if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
			if(grid[nx][ny]=='#') continue;
			if(dist[nx][ny][nz]>dist[x][y][z]+1){
				dist[nx][ny][nz]=dist[x][y][z]+1;
				q.push({nx,ny,nz});
			}
		}
	}

	int d = min(dist[g.F][g.S][0],dist[g.F][g.S][1]);
	cout << ((d<INF)?d:-1);
}