#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	ll l,r;
	cin >> l >> r;

	ll len = r-l;
	ll lo = 1, hi = len+1;
	ll ans = lo;
	while(lo<=hi){
		ll mid = (lo+hi)/2;

		if((mid*(mid-1))/2 <= len){
			ans = mid;
			lo = mid+1;
		}
		else hi = mid-1;
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