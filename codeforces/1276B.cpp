#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,m,a,b; cin >> n >> m >> a >> b;
	vector<vector<int>>g(n+1);

	for(int i=0;i<m;i++){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	function<void(int,int,vector<bool>&)> dfs = [&](int v, int avoid, vector<bool>&vis)->void{
		vis[v]=true;
		for(int ch: g[v]){
			if(ch==avoid || vis[ch]) continue;
			dfs(ch,avoid,vis);
		}
	};

	vector<bool>vis1(n+1,false), vis2(n+1,false);
	int ct1=0,ct2=0;

	dfs(a,b,vis1);
	dfs(b,a,vis2);

	for(int i=1;i<=n;i++){
		ct1 += (vis1[i] && !vis2[i]);
		ct2 += (vis2[i] && !vis1[i]);
	}
	// cout << ct1 << " " << ct2 << endl;
	cout << (ct1-1)*1LL*(ct2-1) << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}