#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];

	vector<ll>dp(n+1); dp[0]=0;
	ll pref=0;
	map<ll,int>mp; mp[pref]=0;

	for(int i=1;i<=n;i++){
		pref+=a[i];
		// cout << pref << " ";
		dp[i]=dp[i-1];
		if(mp.find(pref)!=mp.end()) dp[i]=max(dp[i],1+dp[mp[pref]]);
		mp[pref]=i;
	}

	// for(int i=0;i<=n;i++) cout << dp[i] << " ";
	// cout << endl;
	cout << dp[n] << endl;
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