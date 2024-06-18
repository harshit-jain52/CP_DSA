#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

vector<int>g[N];
ll a[N], insum[N], outsum[N],indp[N], outdp[N];

void indfs(int v, int pp){
	insum[v]=a[v];
	indp[v]=0;

	for(int ch: g[v]){
		if(ch==pp) continue;
		indfs(ch,v);
		insum[v]+=insum[ch];
		indp[v] += indp[ch]+insum[ch];
	}
}

void outdfs(int v, int pp){
	for(int ch: g[v]){
		if(ch==pp) continue;
		outsum[ch] = outsum[v]+insum[v]-insum[ch];
		outdp[ch] += outdp[v]+outsum[ch]+indp[v]-indp[ch]-insum[ch];
		outdfs(ch,v);
	}
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	for(int i=0;i<n-1;i++){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	indfs(1,0);
	outdfs(1,0);

	ll maxd = 0;
	for(int i=1;i<=n;i++) maxd = max(maxd,indp[i]+outdp[i]);
	cout << maxd;
}