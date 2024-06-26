#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	ll n, k;
	cin >> n >> k;

	ll lo = 1, hi = n*n, mid;
	ll ans = lo;

	while(lo<=hi){
		mid = (lo+hi)/2;

		ll ct = 0;
		for(int i=1;i<=n;i++) ct += min(n,(mid/i));

		if(ct>=k){
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}

	cout << ans;
}