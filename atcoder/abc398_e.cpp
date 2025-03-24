#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 105;
#define F first
#define S second

vector<int>g[N];
vector<int>bw[2];

void dfs(int v, int par, int col){
	bw[col].push_back(v);
	for(int ch: g[v]) if(ch!=par) dfs(ch,v,1^col);
}

int main()
{
	int n; cin >> n;
	for(int i=0;i<n-1;i++){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1,0,0);

	set<pair<int,int>>st;
	for(int b: bw[0]){
		for(int w: bw[1]){
			auto it = find(g[b].begin(),g[b].end(),w);
			if(it != g[b].end()) continue;
			if(b<w) st.insert({b,w});
			else st.insert({w,b});
		}
	}

	int sz = st.size();
	if(sz&1){
		cout << "First" << endl;
		auto [u,v] = *st.begin();
		cout << u << " " << v << endl;
		st.erase(st.begin());
	}
	else{
		cout << "Second" << endl;
	}

	while(1){
		int i,j; cin >> i >> j;
		if(i==-1 && j==-1) break;
		if(i>j) swap(i,j);
		st.erase(st.find({i,j}));

		auto [u,v] = *st.begin();
		cout << u << " " << v << endl;
		st.erase(st.begin());
	}
}