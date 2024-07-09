#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const int M = 1e9+7;

bool solve(){
	int n,m,k;
	cin >> n >> m >> k;

	ll a[n][m];
	REP(i,n) REP(j,m) cin >> a[i][j];

	ll sum0=0,sum1=0;

	vector<vector<int>>pref(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c; cin >> c;
			if(c=='0'){
				sum0+=a[i-1][j-1];
				pref[i][j]=1;
			}
			else{
				sum1 += a[i-1][j-1];
				pref[i][j]=-1;
			}
			pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
		}
	}

	if(sum0==sum1) return true;
	
	ll diff = abs(sum0-sum1);
	int g = 0;
	for(int i=k;i<=n;i++){
		for(int j=k;j<=m;j++){
			int sub = pref[i][j] - pref[i-k][j] - pref[i][j-k] + pref[i-k][j-k];
			g = __gcd(g,abs(sub));
		}
	}

	if(g==0) return false;
	return (diff%g==0);
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}