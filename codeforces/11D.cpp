#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 19;

bool g[N][N];
ll dp[N][1<<N]; // dp[v][mask] = no. of simple paths ending at v and having nodes of mask

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	while(m--){
		int a,b; cin >> a >> b;
		a--; b--;
		g[a][b] = g[b][a] = 1;
	}

	for(int i=0;i<n;i++) dp[i][1<<i]=1;

	ll ct = 0;

	for(int mask=1;mask<(1<<n);mask++){
		int first = __builtin_ffsl(mask)-1;
		for(int last=first;last<n;last++){
			if((mask>>last)&1){
				for(int nxt=first+1;nxt<n;nxt++){
					if(g[last][nxt] && ((mask>>nxt)&1)==0){
						dp[nxt][mask|(1<<nxt)] += dp[last][mask];
					}
				}
			}
		}

		if(__builtin_popcount(mask)<3) continue;
		for(int last=first+1;last<n;last++){
			if(g[first][last]) ct += dp[last][mask];
		}
	}

	cout << ct/2;
}