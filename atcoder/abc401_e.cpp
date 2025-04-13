#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const int N = 2e5+5;

int par[N], sz[N];

void Make(int v){
	par[v]=v;
	sz[v]=1;
}

int Find(int v){
	return ((par[v]==v)?v:par[v]=Find(par[v]));
}

void Union(int u, int v){
	u = Find(u); v = Find(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];
	par[v]=u;
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	vector<pii>e1,e2;
	for(int i=0;i<m;i++){
		int u,v; cin >> u >> v;
		e1.emplace_back(u,v);
		e2.emplace_back(v,u);
	}
	sort(e1.begin(),e1.end());
	sort(e2.begin(),e2.end());

	vector<bool>possible(n+1,false);
	for(int i=1;i<=n;i++) Make(i);

	int j=0;
	for(int k=1;k<=n;k++){
		while(j<m && e2[j].F<=k){
			Union(e2[j].F,e2[j].S);
			j++;
		}
		possible[k] = (sz[Find(1)]==k);
	}
	// for(int k=1;k<=n;k++) cout << possible[k] << endl;

	set<int>st;
	vector<int>ans(n+1,-1);
	j=0;
	for(int k=0;k<=n;k++){
		while(j<m && e1[j].F<=k){
			st.insert(e1[j].F);
			st.insert(e1[j].S);
			j++;
		}
		if(possible[k]) ans[k] = ((int)st.size() - k);
	}
	if(ans[1]==-1) ans[1]=0;
	for(int k=1;k<=n;k++) cout << ans[k] << endl;
}