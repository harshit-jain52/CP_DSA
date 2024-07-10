#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
int h,w;
vector<string>grid;
vector<vector<bool>>vis;
vector<pair<int,int>>moves{{1,0},{0,1},{-1,0},{0,-1}};

char nextC(char c){
	if(c=='s') return 'n';
	if(c=='n') return 'u';
	if(c=='u') return 'k';
	if(c=='k') return 'e';
	else return 's';
}

inline bool check(int x, int y, char c){
	return (x>=0 && y>=0 && x<h && y<w && !vis[x][y] && grid[x][y]==c);
}

void dfs(int x, int y){
	vis[x][y] = true;

	for(auto [dx,dy]: moves){
		int nx=x+dx,ny=y+dy;
		char c = nextC(grid[x][y]);

		if(check(nx,ny,c)) dfs(nx,ny);
	}
}

int main()
{
	FASTIO
	cin >> h >> w;

	grid.resize(h);
	vis.assign(h,vector<bool>(w,false));
	for(int i=0;i<h;i++) cin >> grid[i];

	if(grid[0][0]!='s'){
		cout << "No";
		return 0;
	}

	dfs(0,0);
	if(vis[h-1][w-1]) cout << "Yes";
	else cout << "No";
}