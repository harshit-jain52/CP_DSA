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

struct Edge{
	int a;
	int b;
	bool mark;
	Edge(){a=b=mark=0;}
};

int par[N], sz[N];

void Make(int v){
	par[v]=v;
	sz[v]=1;
}

int Find(int v){
	return ((par[v]==v)?v:(par[v]=Find(par[v])));
}

bool Union(int u, int v){
	u = Find(u); v = Find(v);
	if(u==v) return true;
	if(sz[u]<sz[v]) swap(u,v);

	sz[u]+=sz[v];
	par[v]=u;
	return false;
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++) Make(i);

	vector<Edge>e(m);
	for(int i=0;i<m;i++){
		cin >> e[i].a >> e[i].b;
		e[i].mark = Union(e[i].a,e[i].b);
	}


	map<int,vector<int>>mp;
	for(int i=1;i<=n;i++) mp[Find(i)]=vector<int>();

	for(int i=0;i<m;i++){
		if(e[i].mark) mp[Find(e[i].a)].push_back(i);
	}

	vector<pii>vec;
	for(auto it: mp){
		vec.push_back({it.S.size(),it.F});
	}
	sort(vec.rbegin(),vec.rend());

	int sz = vec.size()-1;
	cout << sz << endl;
	int j=0, i=1;
	
	while(j<=sz){
		while(vec[j].F--){
			int x = mp[vec[j].S][vec[j].F];
			if(i<=sz){
				cout << x+1 << " " << e[x].a << " " << vec[i].S << endl;
				i++;	
			}
		}
		j++;
	}
}