#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

struct Edge{
	int a,b,idx;
	ll w;

	Edge(){}
	bool operator<(Edge other){
		return w < other.w;
	}
};

struct DSU{
	vector<int>par;
	vector<int>sz;

	DSU(int n=1){
		par.assign(n+1,0);
		sz.assign(n+1,1);
		for(int i=1;i<=n;i++) par[i]=i;
	}

	int Find(int v){
		return ((par[v]==v)?v:par[v]=Find(par[v]));
	}

	void Union(int u, int v){
		u = Find(u), v = Find(v);
		if(u==v) return;

		if(sz[u]<sz[v]) swap(u,v);
		sz[u]+=sz[v];
		par[v]=u;
	}
};

int main()
{
	FASTIO
	int n,m; ll s;
	cin >> n >> m >> s;

	DSU g(n);
	vector<Edge>eg(m);

	for(int i=0;i<m;i++){
		cin >> eg[i].a >> eg[i].b >> eg[i].w;
		eg[i].idx=i+1;	
	}

	sort(eg.begin(),eg.end());
	vector<Edge>del;

	for(int i=m-1;i>=0;i--){
		if(g.Find(eg[i].a)==g.Find(eg[i].b)) del.push_back(eg[i]);
		else g.Union(eg[i].a,eg[i].b);
	}

	int sz = del.size();
	ll pref=0;
	vector<int>indices;
	for(int i=sz-1;i>=0;i--){
		if(pref+del[i].w>s) break;
		pref += del[i].w;
		indices.push_back(del[i].idx);
	}

	sort(indices.begin(),indices.end());
	cout << indices.size() << endl;
	for(auto it : indices) cout << it << " ";
}