#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,k; cin >> n >> k;
	ll a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	ll lo = *max_element(a,a+n), hi = accumulate(a,a+n,0LL), mid;
	ll ans = hi;

	while(lo<=hi){
		mid = (lo+hi)/2;

		int ct=1; ll pref=0;
		for(int i=0;i<n;i++){
			if(pref+a[i]>mid){
				ct++;
				pref=0;
			}
			pref+=a[i];
		}

		if(ct<=k){
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}

	cout << ans;
}