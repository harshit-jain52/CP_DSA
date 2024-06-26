#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	double err = 1e-7;
	double lo=err, hi = *max_element(a,a+n), mid;
	double ans = lo;

	while(hi-lo>=err){
		mid = (lo+hi)/2;
		ll ct = 0;

		for(int i=0;i<n;i++) ct += a[i]/mid;
		if(ct>=k){
			ans = mid;
			lo=mid+err;
		}
		else hi = mid-err;
	}

	cout << fixed<<setprecision(6) << ans;
}