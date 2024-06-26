#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; ll k;
	cin >> n >> k;
	ll l[n],r[n];
	for(int i=0;i<n;i++) cin >> l[i] >> r[i];

	ll lo = *min_element(l,l+n) - 1, hi = *max_element(r,r+n), mid;
	ll ans=lo;

	while(lo<=hi){
		mid = (lo+hi)/2;

		ll ct=0;
		for(int i=0;i<n;i++){
			ll lim  = min(mid,r[i]);
			if(lim>=l[i]) ct += (lim-l[i]+1);
		}
		if(ct<=k){
			ans = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}

	cout << ans+1;
}