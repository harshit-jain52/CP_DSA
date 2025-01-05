#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

vector<int>g[N];
int indp[N], outdp[N];

void dfs(int v, int par){
	indp[v]=outdp[v]=g[v].size();
	int chmx1 = 0, chmx2 = 0;
	for(int ch: g[v]){
		if(ch==par) continue;
		dfs(ch,v);
		indp[v]=max(indp[v],indp[ch]+(int)g[v].size()-2);
		if(indp[ch]>chmx1){
			chmx2=chmx1;
			chmx1=indp[ch];
		} else if(indp[ch]>chmx2){
			chmx2 = indp[ch];
		}
	}

	if(chmx2){
		outdp[v] = chmx1+chmx2+g[v].size()-4;
	}
}

void solve(){
	int n; cin >> n;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=0;i<n-1;i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	// for(int i=1;i<=n;i++) cout << indp[i] << " ";
	// cout << endl;
	// for(int i=1;i<=n;i++) cout << outdp[i] << " ";
	// cout << endl;
	
	int ans = 1;
	for(int i=1;i<=n;i++){
		ans =max({ans,indp[i],outdp[i]});
	}
	cout << ans << endl;
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