#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct Edge{
	int u, v;
	ll wt;
	Edge(){}

	bool operator<(Edge other){
		return wt < other.wt;
	}
};

int par[N], sz[N];

void make(int i){
	par[i]=i;
	sz[i]=1;
}

int Find(int v){
	if(v==par[v]) return v;
	return par[v]=Find(par[v]);
}

void Union(int u, int v){
	u = Find(u); v = Find(v);
	if(u==v) return;

	if(sz[u]<sz[v]) swap(u,v);
	par[v]=u;
	sz[u]+=sz[v];
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=1;i<=n;i++) make(i);

	vector<Edge>vec(n-1);
	for(int i=0;i<n-1;i++) cin >> vec[i].u>>vec[i].v>>vec[i].wt;

	sort(vec.begin(),vec.end());
	
	ll ans = 0;
	for(int i=0;i<n-1;i++){
		ans += sz[Find(vec[i].u)]*vec[i].wt*sz[Find(vec[i].v)];
		Union(vec[i].u,vec[i].v);
	}
	cout << ans;
}