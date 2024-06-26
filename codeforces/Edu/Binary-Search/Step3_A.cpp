#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const double err = 1e-7;

int main()
{
	FASTIO
	int n; cin >> n;
	ll x[n], v[n];
	for(int i=0;i<n;i++) cin >> x[i] >> v[i];

	ll xmin = *min_element(x,x+n);
	ll xmax = *max_element(x,x+n);

	double lo = 0, hi = 1e9+1, mid;
	double ans = hi;

	while(hi-lo>=err){
		mid = (lo+hi)/2;

		double lmax = xmin, rmin = xmax;
		for(int i=0;i<n;i++){
			lmax = max(lmax,x[i]-mid*v[i]);
			rmin = min(rmin,x[i]+mid*v[i]);
		}

		if(lmax<=rmin){
			ans = mid;
			hi = mid-err;
		}
		else lo = mid+err;
	}

	cout << fixed << setprecision(6)<<ans;
}