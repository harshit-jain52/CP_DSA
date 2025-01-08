#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
vector<vector<int>>dp;

void solve(){
	string a,b,c; cin >> a >> b >> c;
	// cout << a << " " << b << " " << c << endl;	
	int n = a.size(), m = b.size();

	dp.assign(n+1,vector<int>(m+1,0));
	

	for(int i=1;i<=n;i++) dp[i][0]=dp[i-1][0]+(a[i-1]!=c[i-1]);	
	for(int j=1;j<=m;j++) dp[0][j]=dp[0][j-1]+(b[j-1]!=c[j-1]);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=min(dp[i-1][j]+(c[i+j-1]!=a[i-1]),dp[i][j-1]+(c[i+j-1]!=b[j-1]));
		}
	}

	cout << dp[n][m] << endl;
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