#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;
const int INF = M;

vector<int>g[N];
vector<int> a(N), ans(N), dp(N,INF);

void dfs(int v, int p){
	int len = lower_bound(dp.begin(),dp.end(),a[v])-dp.begin();
	int temp = dp[len];
	
	dp[len]=a[v];
	ans[v] = lower_bound(dp.begin(),dp.end(),INF)-dp.begin()-1;

	for(int ch: g[v]) if(ch!=p) dfs(ch,v);
	dp[len]=temp;
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dp[0]=-INF;
	dfs(1,0);
	for(int i=1;i<=n;i++) cout << ans[i] << endl;
}