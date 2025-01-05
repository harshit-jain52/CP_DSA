#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 5e5+5;

int a[N], par[N], sz[N], mx[N];

void Make(int v){
	par[v]=v;
	sz[v]=1;
	mx[v]=a[v];
}

int Find(int v){
	return ((par[v]==v)?v:par[v]=Find(par[v]));
}

void Union(int u, int v){
	u = Find(u); v = Find(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);

	par[v]=u;
	sz[u]+=sz[v];
	mx[u]=max(mx[u],mx[v]);
}

void solve(){
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		Make(i);
	}

	int pmx=0;
	for(int i=0;i<n;i++){
		if(a[pmx]<a[i]) pmx=i;
		Union(i,pmx);
	}

	vector<int>vec;
	int smn=n-1;
	for(int i=n-1;i>=0;i--){
		if(a[smn]>a[i]) smn=i;

		int x = vec.size() - (upper_bound(vec.begin(),vec.end(),-a[i]) - vec.begin());
		vec.push_back(-a[smn]);
		// cout << i << " " << x << endl;
		Union(i,i+x);
	}

	for(int i=0;i<n;i++) cout << mx[Find(i)] << " ";
	cout << endl;
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