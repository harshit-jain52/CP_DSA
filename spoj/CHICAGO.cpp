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
	while(1){
		int n,m;
		cin >> n;
		if(n==0) break;
		cin >> m;

		double prob[n][n];
		REP(i,n) REP(j,n) prob[i][j]=(i==j);

		while(m--){
			int a,b; double p;
			cin >> a >> b >> p;
			a--; b--; p/=100;

			prob[a][b] = max(prob[a][b],p);
			prob[b][a] = max(prob[b][a],p);
		}

		REP(k,n) REP(i,n) REP(j,n) prob[i][j] = max(prob[i][j],prob[i][k]*prob[k][j]);

		double per = prob[0][n-1]*100;

		cout << fixed<<setprecision(6)<<per<<" percent\n";
	}
}