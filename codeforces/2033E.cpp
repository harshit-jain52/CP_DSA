#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e6+6;

int par[N], sz[N];

void make(int i){
	sz[i]=1;
	par[i]=i;
}

int Find(int i){
	if(par[i]==i) return i;
	return par[i]=Find(par[i]);
}

void Union(int u, int v){
	u = Find(u), v = Find(v);
	if(u==v) return;

	if(sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];
	par[v]=u;
}

void solve(){
	int n; cin >> n;
	int p[n+1];
	for(int i=1;i<=n;i++) make(i);
	for(int i=1;i<=n;i++){
		cin >> p[i];
		Union(i,p[i]);
	}

	set<int>st;
	for(int i=1;i<=n;i++) st.insert(Find(i));

	int ans = 0;
	// for(int v: st) cout << sz[v] << " ";
	// cout << endl;
	for(int v: st){
		ans += (sz[v]-1)/2;
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