#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; cin >> n;
	int dist[n][n];

	REP(i,n) REP(j,n) cin >> dist[i][j];

	int k; cin >> k;
	while(k--){
		int a,b,c; cin >> a >> b >> c;
		a--; b--;
		dist[a][b]=min(dist[a][b],c);
		dist[b][a]=min(dist[b][a],c);

		REP(i,n) REP(j,n) dist[i][j] = min({dist[i][j],dist[i][a]+dist[a][b]+dist[b][j],dist[i][b]+dist[b][a]+dist[a][j]});

		ll sum = 0;
		REP(i,n) REP(j,n) sum += dist[i][j];

		cout << sum/2 << " ";
	}
}