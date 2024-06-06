#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
int n;
bool isLucky(int n){
	while(n>0){
		int d = n%10;
		if(d!=4 && d!=7) return false;
		n/=10;
	}
	return true;
}

vector<pair<int,bool>>g[N];
int subSz[N],indp[N], outdp[N];

void indfs(int v, int par){
	subSz[v]=1;
	indp[v]=0;

	for(auto ch: g[v]){
		if(ch.F==par) continue;
		indfs(ch.F,v);

		subSz[v]+=subSz[ch.F];
		if(ch.S) indp[v] += subSz[ch.F];
		else indp[v] += indp[ch.F];
	}
}

void outdfs(int v,int par){
	if(par==-1) outdp[v]=0;

	for(auto ch: g[v]){
		if(ch.F == par) continue;
		if(ch.S) outdp[ch.F] = n-subSz[ch.F];
		else outdp[ch.F] = outdp[v]+indp[v]-indp[ch.F];

		outdfs(ch.F,v);
	}
}

int main()
{
	FASTIO
	cin >> n;
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,isLucky(w)});
		g[v].push_back({u,isLucky(w)});
	}

	indfs(1,-1);
	outdfs(1,-1);

	ll ans = 0;

	for(int i=1;i<=n;i++){
		ll tmp1 =  indp[i]*1LL*(indp[i]-1);
		ll tmp2 =  outdp[i]*1LL*(outdp[i]-1);
		ll tmp3 =  indp[i]*2LL*outdp[i];
		ans += (tmp1+tmp2+tmp3);
	}

	cout << ans;
}