#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int k,n;
	cin >> k >> n;
	ll a[n], tot=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		tot += a[i];
	}

	ll lo=1,hi=tot/k,mid;
	ll ans = lo;
	while(lo<=hi){
		mid = (lo+hi)/2;

		ll tmp=0;
		for(int i=0;i<n;i++) tmp += min(a[i],mid);

		if(tmp>=mid*k){
			ans = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}

	cout << ans;
}
