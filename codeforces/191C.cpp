#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
const int LOG = 20;

vector<int>g[N];
int d[N],up[N][LOG];
int ct[N];

void dfs(int v, int pp, int dep){
	up[v][0]=pp;
	d[v]=dep;
	for(int i=1;i<LOG;i++) up[v][i] = up[up[v][i-1]][i-1];
	for(int ch: g[v]) if(ch!=pp) dfs(ch,v,dep+1);
}

int LCA(int u, int v){
	if(d[u]<d[v]) swap(u,v);
	
	for(int i=LOG-1;i>=0;i--){
		if((d[u]-d[v])&(1<<i)) u = up[u][i];
	}

	if(u==v) return u;

	for(int i=LOG-1;i>=0;i--){
		if(up[u][i]!=up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}

	return up[u][0];
}

void pushAll(int v, int pp){
	for(int ch: g[v]) if(ch!=pp) pushAll(ch,v);
	ct[pp] += ct[v];
}

int main()
{
	FASTIO
	int n; cin >> n;
	vector<pair<int,int>>edg(n-1);
	for(int i=0;i<n-1;i++){
		int u,v; cin >> u >> v;
		edg[i]={u,v};
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1,0,0);

	int k; cin >> k;
	while(k--){
		int a,b; cin >> a >> b;
		int lc = LCA(a,b);
		ct[a]++;
		ct[b]++;
		ct[lc]-=2;
	}

	pushAll(1,0);
	for(int i=0;i<n-1;i++){
		int u = edg[i].first, v = edg[i].second;
		if(d[u]<d[v]) swap(u,v);
		cout << ct[u]<<" ";
	}
}