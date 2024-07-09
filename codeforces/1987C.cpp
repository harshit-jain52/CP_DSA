#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	ll h[n];
	for(int i=0;i<n;i++) cin >> h[i];

	ll dp[n];
	dp[n-1] = h[n-1];
	for(int i=n-2;i>=0;i--){
		if(h[i]<=h[i+1]) dp[i] = dp[i+1]+1;
		else dp[i] = max(dp[i+1]+1,h[i]);
	}

	ll ans = *max_element(dp,dp+n);
	cout << ans << endl;
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