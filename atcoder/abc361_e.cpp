#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;
#define F first
#define S second

vector<pair<int,ll>>g[N];

void dfs(int v, int pp, vector<ll>&dist, ll d){
	dist[v]=d;
	for(auto ch: g[v]) if(ch.F!=pp) dfs(ch.F,v,dist,d+ch.S);
}

int main()
{
	FASTIO
	int n; cin >> n;
	ll tot = 0;
	for(int i=0; i<n-1;i++){
		int a,b; ll c;
		cin >> a >> b >> c;
		tot += 2*c;

		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}

	vector<ll>dist(n+1);
	dfs(1,0,dist,0);
	int maxi=1;
	for(int i=1;i<=n;i++) if(dist[i]>dist[maxi]) maxi=i;

	dfs(maxi,0,dist,0);
	ll diam = 0;
	for(int i=1;i<=n;i++) diam=max(diam,dist[i]);

	cout << tot-diam;
}