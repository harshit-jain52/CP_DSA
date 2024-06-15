#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;
const int N = 5e4+5;

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
	int n,m,k; cin >> n >> m >> k;
	for(int i=1;i<=n;i++) make(i);

	vector<pair<int,int>>edges(m);
	for(int i=0;i<m;i++) cin >> edges[i].F >> edges[i].S;

	vector<pair<string,pair<int,int>>>qu(k);
	for(int i=0;i<k;i++) cin >> qu[i].F >> qu[i].S.F >> qu[i].S.S;

	stack<bool>ans;
	for(int i=k-1;i>=0;i--){
		if(qu[i].F=="cut") Union(qu[i].S.F,qu[i].S.S);
		else ans.push(Find(qu[i].S.F)==Find(qu[i].S.S));
	}

	while(!ans.empty()){
		if(ans.top()) cout << "YES\n";
		else cout << "NO\n";
		ans.pop();
	}
}