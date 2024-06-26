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

	ll a[n], b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];

	sort(a,a+n);
	sort(b,b+n);

	ll lo = a[0]+b[0], hi = a[n-1]+b[n-1], mid;
	ll ans = lo;

	while(lo<=hi){
		mid = (lo+hi)/2;

		ll ct = 0;

		for(int i=0;i<n;i++){
			auto it = upper_bound(b,b+n,mid-a[i]);
			ct += (it-b);
		}

		if(ct>=k){
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}

	cout << ans;
}