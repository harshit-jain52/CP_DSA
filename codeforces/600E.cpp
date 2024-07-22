#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

vector<int>g[N];
map<int,int>colors[N];
map<int,ll>sum[N];
ll ans[N];

void dfs(int v, int pp){
	for(int ch: g[v]){
		if(ch==pp) continue;
		dfs(ch,v);

		if(colors[v].size()<colors[ch].size()){
			colors[v].swap(colors[ch]);
			sum[v].swap(sum[ch]);
		}

		for(auto [c,occ]: colors[ch]){

			if(colors[v].find(c) != colors[v].end()){
				sum[v][colors[v][c]]-=c;
			}
		
			colors[v][c]+=occ;
			sum[v][colors[v][c]]+=c;
		}
	}

	auto it = sum[v].end();
	it--;

	ans[v] = it->second;
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		int c; cin >> c;
		colors[i][c]++;
		sum[i][1]+=c;
	}

	for(int i=0;i<n-1;i++){
		int x,y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1,0);
	for(int i=1;i<=n;i++) cout << ans[i] << " ";
}