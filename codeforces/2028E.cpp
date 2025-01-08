#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;
const int N = 2e5+5;
vector<int>g[N];
vector<int>leaves;
int d[N], h[N], par[N];

bool cmp(int u, int v){
	return d[u]<d[v];
}

void dfs(int v, int p, int dep){
	d[v]=dep;
	par[v]=p;

	if(v!=1 && (int)g[v].size()==1){
		h[v]=0;
		leaves.push_back(v);
	}
	else h[v]=N;

	for(auto ch: g[v]){
		if(ch==p) continue;
		dfs(ch,v,1+dep);
		h[v]=min(h[v],1+h[ch]);
	}
}

int binpow(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans=(ans*1LL*a)%M;
		a = (a*1LL*a)%M;
		b>>=1;
	}
	return ans;
}

inline int modinv(int a){
	return binpow(a,M-2);
}

void solve(){
	// GAMBLER'S RUIN
	int n; cin >> n;
	for(int i=1;i<=n;i++) g[i].clear();
	leaves.clear();

	for(int i=0;i<n-1;i++){
		int x,y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1,0,0);
	vector<int>ans(n+1,-1);
	ans[1]=1;

	sort(leaves.begin(),leaves.end(),cmp);
	for(auto l: leaves){
		int cur=l, ct=0;
		while(ans[cur]==-1){
			cur=par[cur];
			ct++;
		}

		int len=0, prob=ans[cur], deno=modinv(ct);
		// cout << cur << " " << prob << endl;
		cur=l;
		while(ans[cur]==-1){
			ans[cur]=(prob*1LL*((len*1LL*deno)%M))%M;
			len++;
			cur=par[cur];
		}

	}

	for(int i=1;i<=n;i++) cout << ans[i] << " ";
	cout << endl;
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