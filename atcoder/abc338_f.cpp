#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const int M = 1e9+7;
const int INF = 1e8;
const int N = 20;

int dp[N][1<<N], wt[N][N];
int n;

int func(int v, int mask){
	if(__builtin_popcount(mask)==n) return 0;
	if(dp[v][mask]!=-INF) return dp[v][mask];

	int ans = INF;
	REP(i,n){
		if(((mask>>i)&1)==0 && wt[v][i]<INF){
			int x = func(i,mask|(1<<i));
			if(x<INF) ans = min(ans,wt[v][i]+x);
		}
	}

	return dp[v][mask]=ans;
}

int main()
{
	FASTIO
	int m; cin >> n >> m;

	REP(i,n) REP(j,(1<<n)) dp[i][j]=-INF;
	REP(i,n) REP(j,n) wt[i][j]=INF;

	REP(i,n) wt[i][i]=0;

	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		u--; v--;
		wt[u][v] = min(wt[u][v],w);
	}

	REP(k,n) REP(i,n) REP(j,n){
		if(wt[i][k]!=INF && wt[k][j]!=INF)
			wt[i][j] = min(wt[i][j],wt[i][k]+wt[k][j]);
	}

	int ans = INF;
	REP(i,n) ans = min(ans,func(i,(1<<i)));
	if(ans<INF) cout << ans;
	else cout << "No";
}