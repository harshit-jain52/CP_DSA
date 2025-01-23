#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e9+7;
#define F first
#define S second

struct DSU{
	vector<int>par, sz;
	vector<pii>e;
	DSU(int n){
		par.resize(n+1);
		sz.assign(n+1,1);
		for(int i=1;i<=n;i++) par[i]=i;
	}
	
	int Find(int v){
		return ((par[v]==v)?v:Find(par[v]));
	}

	void Union(int u, int v){
		u = Find(u); v = Find(v);
		if(u==v) return;
		if(sz[u]<sz[v]) swap(u,v);
		sz[u]+=sz[v];
		par[v]=u;
	}
};

void solve(){
	int n,m1,m2; cin >> n >> m1 >> m2;
	DSU G(n), F(n);

	for(int i=0;i<m1;i++){
		int u,v; cin >> u >> v;
		F.e.push_back({u,v});
	}
	for(int i=0;i<m2;i++){
		int u,v; cin >> u >> v;
		G.e.push_back({u,v});
		G.Union(u,v);
	}

	int ct=0;
	for(auto [u,v]: F.e){
		if(G.Find(u)!=G.Find(v)) ct++;
		else F.Union(u,v);
	}

	for(auto [u,v]: G.e){
		if(F.Find(u)!=F.Find(v)){
			ct++;
			F.Union(u,v);
		}
	}
	cout << ct << endl;
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