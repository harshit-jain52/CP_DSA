#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const ll INF = 1e18;
#define F first
#define S second

int main()
{
	FASTIO
	int n, m; cin >> n >> m;

	vector<vector<pair<int,ll>>>g(n+1);

	while(m--){
		int u,v,w; cin >> u >> v >> w;
		if(w==0) continue;
		g[u].push_back({v,w});
		g[v].push_back({u,-w});
	}

	vector<ll>ans(n+1,INF+1);

	function<void(int)> dfs = [&](int v) -> void{
		for(auto ch: g[v]){
			if(ans[ch.F]<=INF) continue;
			ans[ch.F] = ans[v] + ch.S;
			dfs(ch.F);
		}
	};

	for(int i=1;i<=n;i++){
		if(ans[i]<=INF) continue;
		ans[i]=0;
		dfs(i);
	}

	for(int i=1;i<=n;i++) cout << ans[i] << " ";
}