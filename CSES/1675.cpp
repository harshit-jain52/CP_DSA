#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

int par[N];
int set_size[N];

void make(int v){
	par[v]=v;
	set_size[v]=1;
}

int find(int v){
	if(v==par[v]) return v;
	return par[v]=find(par[v]);
}

void unionBySize(int a, int b){
	a = find(a);
	b = find(b);

	if(a==b) return;

	if(set_size[a]<set_size[b]) swap(a,b);

	par[b]=a;
	set_size[a]+=set_size[b];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin >> n >> m;

	for(int i=1;i<=n;i++) make(i);

	vector<pair<ll,pair<int,int>>> edges;
	while(m--){
		int a,b;
		ll c;
		cin >> a >> b >> c;
		edges.push_back({c,{a,b}});
	}

	sort(edges.begin(),edges.end());

	ll min_cost = 0;

	for(auto e: edges){
		ll c = e.first;
		int a = e.second.first;
		int b = e.second.second;

		if(find(a)==find(b)) continue;

		min_cost+=c;
		unionBySize(a,b);
	}

	if(set_size[find(1)]!=n) cout << "IMPOSSIBLE";
	else cout << min_cost;
}