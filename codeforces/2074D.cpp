#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,m; cin >> n >> m;
	ll x[n], r[n];
	for(int i=0;i<n;i++) cin >> x[i];
	for(int i=0;i<n;i++) cin >> r[i];

	map<ll,ll>mp;
	for(int i=0;i<n;i++){
		ll lo = x[i]-r[i], hi = x[i]+r[i];
		for(ll z = lo; z <= hi; z++){
			ll y = sqrtf(r[i]*r[i] - (z-x[i])*(z-x[i]));
			mp[z]=max(mp[z],y);
		}
	}

	ll ans = mp.size();
	for(auto it: mp){
		ans += 2*it.second;
	}
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