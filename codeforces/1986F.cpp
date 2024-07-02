#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
typedef pair<int,int> pii;
#define F first
#define S second

vector<vector<int>>g;
vector<int>lo, tin;
vector<int>compsz;
int timer,n;

void reset(){
	g.assign(n+1,vector<int>());
	lo.assign(n+1,0);
	tin.assign(n+1,0);
	compsz.assign(n+1,0);
	timer=0;
}

void dfsBR(int cur, int par, ll &ans){
	tin[cur]=lo[cur]= ++timer;
	compsz[cur]=1;
	for(int ch: g[cur]){
		if(ch==par) continue;

		if(tin[ch]) lo[cur]=min(lo[cur],tin[ch]);
		else{
			dfsBR(ch,cur,ans);
			if(lo[ch]>tin[cur]) ans = max(ans,compsz[ch]*1LL*(n-compsz[ch]));
			lo[cur] = min(lo[cur],lo[ch]);
			compsz[cur]+=compsz[ch];
		}
	}
}

void solve(){
	int m; cin >> n >> m;
	reset();

	while(m--){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll ans = 0;
	dfsBR(1,0,ans);

	ll tot = n*1LL*(n-1)/2;
	cout << tot-ans << endl;
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