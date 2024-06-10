#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	ll a[n];

	for(int i=0;i<n;i++) cin >> a[i];

	ll dp[n][2];
	dp[0][0] = a[0];
	dp[0][1] = abs(a[0]);

	for(int i=1;i<n;i++){
		dp[i][0] = a[i]+ dp[i-1][0];
		dp[i][1] = max(abs(a[i]+dp[i-1][0]),abs(a[i]+dp[i-1][1]));
	}

	cout << max(dp[n-1][1],dp[n-1][0])<<endl;
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