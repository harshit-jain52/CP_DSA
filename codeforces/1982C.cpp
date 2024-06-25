#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	ll l,r; cin >> l >> r;

	ll a[n+1];
	for(int i=1;i<=n;i++) cin >> a[i];

	ll dp[n+1]; dp[0]=0;
	ll pref=0;
	vector<ll>ms;
	ms.push_back(pref);
	for(int i=1;i<=n;i++){
		pref += a[i];
		dp[i]=dp[i-1];

		if(pref>=l){
			auto it = upper_bound(ms.begin(),ms.end(),pref-l);
			if(it!=ms.begin()){
				it--;
				int idx = it-ms.begin();
				if(pref-ms[idx]<=r) dp[i]=max(dp[i],1+dp[idx]);
			}
		}

		ms.push_back(pref);
	}

	cout << dp[n]<<endl;
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