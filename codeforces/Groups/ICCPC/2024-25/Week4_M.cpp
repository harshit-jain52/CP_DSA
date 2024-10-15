#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,m,k; cin >> n >> m >> k;
	int a[n];

	for(int i=0;i<n;i++) cin >> a[i];

	ll lo = (*max_element(a,a+n)+k-1)/k, hi = accumulate(a,a+n,0);
	ll ans = hi;

	while(lo<=hi){
		ll mid = (lo+hi)/2;

		ll curr = 0;
		ll ct = 1;

		for(int i=0;i<n;i++){
			if(curr+a[i]>k*mid){
				curr = 0;
				ct++;
			}
			curr += a[i];
		}

		if(ct<=m){
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}

	cout << ans;
}