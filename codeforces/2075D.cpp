#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 58;
const ll INF = (1LL<<62);
#define MSB(x) (63-__builtin_clzll(x))

ll dp[N][N][N];
vector<vector<ll>>res(N,vector<ll>(N,INF));
vector<vector<ll>>suff(N,vector<ll>(N,INF));

ll func(int k, int a, int b){
	if(k<0){
		if(a==0 && b==0) return 0;
		else return INF;
	}
	if(dp[k][a][b]!=-1) return dp[k][a][b];

	ll ans = func(k-1,a,b);
	if(a>=k) ans = min(ans,(1LL<<k)+func(k-1,a-k,b));
	if(b>=k) ans = min(ans,(1LL<<k)+func(k-1,a,b-k));
	res[a][b] = min(res[a][b],ans);
	return dp[k][a][b]=ans;
}


void solve(){
	ll x,y; cin >> x >> y;

	int a = MSB(x), b = MSB(y);
	// cout << a << " " << b << endl;

	int i=a, j=b;
	ll ans = INF;
	while(i>=0 && j>=0){
		if((x>>i) != (y>>j)) break;
		ans = min(ans,res[i][j]);
		i--;
		j--;
	}

	ans = min(ans,suff[a+(x!=0)][b+(y!=0)]);
	cout << ans << endl;
}

int main(){
	FASTIO
	memset(dp,-1,sizeof(dp));
	for(int i=N-1;i>=0;i--){
		for(int j=N-1;j>=0;j--){
			func(N-1,i,j);
			suff[i][j]=res[i][j];
			if(i+1<N) suff[i][j]=min(suff[i][j],suff[i+1][j]);
			if(j+1<N) suff[i][j]=min(suff[i][j],suff[i][j+1]);
		}
	}

	int t; cin >> t;
	while(t--) solve();
}