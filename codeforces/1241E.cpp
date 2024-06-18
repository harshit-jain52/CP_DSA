#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const int N = 5e5+5;

vector<pii> g[N];
ll dp[N][2];
int k;

void dfs(int v, int pp){
	dp[v][0]=dp[v][1]=0;

	vector<ll>vec;
	for(auto ch: g[v]){
		if(ch.F==pp) continue;
		dfs(ch.F,v);
		dp[v][0] += dp[ch.F][1];
		vec.push_back(dp[ch.F][0]+ch.S-dp[ch.F][1]);
	}

	sort(vec.begin(),vec.end(),[&](ll a, ll b){return a>b;});

	int sz = vec.size();
	ll tmp = dp[v][0];
	for(int i=0;i<min(k-1,sz);i++){
		tmp += vec[i];
		dp[v][0] = max(dp[v][0],tmp);
	}

	dp[v][1]=dp[v][0];
	if(k<=sz) dp[v][1] = max(dp[v][1],tmp+vec[k-1]);
}

void solve(){
	int n;
	cin >> n >> k;

	for(int i=1;i<=n;i++) g[i].clear();

	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	dfs(1,0);
	cout << dp[1][1]<< endl;
}

int main()
{
	FASTIO
	int q; cin >> q;
	while(q--) solve();
}