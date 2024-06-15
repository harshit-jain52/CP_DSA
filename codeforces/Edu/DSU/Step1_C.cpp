#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

int par[N], pending[N], added[N];
vector<int>arr[N];

void make(int i){
	par[i]=i;
	pending[i]=0;
	added[i]=0;
	arr[i]=vector<int>{i};
}

int Find(int v){
	return ((v==par[v])?v:par[v]=Find(par[v]));
}

void Union(int u, int v){
	u = Find(u); v = Find(v);
	if(u==v) return;

	if(arr[u].size()<arr[v].size()) swap(u,v);
	
	par[v]=u;	

	for(int a: arr[v]){
		added[a]+=(pending[v]-pending[u]);
		arr[u].push_back(a);
	}
	arr[v].clear();
}

int main()
{
	FASTIO
	
	int n,m; cin >> n >> m;

	for(int i=1;i<=n;i++) make(i);

	while(m--){
		string type; cin >> type;
		if(type=="join"){
			int x,y; cin >> x >> y;
			Union(x,y);
		}
		else if(type=="add"){
			int x,v; cin >> x >> v;
			pending[Find(x)]+=v;
		}
		else{
			int x; cin >> x;
			cout << added[x]+pending[Find(x)]<<endl;
		}
	}
}