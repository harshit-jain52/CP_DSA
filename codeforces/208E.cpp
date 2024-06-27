#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
const int LOG = 18;

vector<int>g[N];
vector<int>d[N];
int in[N], out[N], depth[N], up[N][LOG];
int timer = 0;

void dfs(int v, int pp, int dep){
	in[v]=timer++;

	if(v!=0){
		up[v][0]=pp;
		depth[v]=dep;
		d[dep].push_back(in[v]);	
		for(int i=1;i<LOG;i++) up[v][i] = up[up[v][i-1]][i-1];
	}

	for(int ch: g[v]) dfs(ch,v,dep+1);

	out[v]=timer++;
}

int kthAnc(int v, int k){
	for(int i=LOG-1;i>=0;i--){
		if((k>>i)&1) v = up[v][i];
	}
	return v;
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		int r; cin >> r;
		g[r].push_back(i);
	}

	dfs(0,0,0);

	int m; cin >> m;
	while(m--){
		int v,p; cin >> v >> p;
		int a = kthAnc(v,p);

		if(a==0) cout << 0 << " ";
		else{
			int dep = depth[v];
			auto it1 = lower_bound(d[dep].begin(),d[dep].end(),in[a]);
			auto it2 = lower_bound(d[dep].begin(),d[dep].end(),out[a]);
			int num = it2-it1;
			cout << num-1 << " ";
		}
	}
}