#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const double err = 1e-7;

double binsqrt(double x){
	double lo=err,hi=x,mid;
	double ans = hi;
	while(hi-lo>=err){
		mid = (lo+hi)/2;
		if(mid*mid <=x){
			ans = mid;
			lo = mid+err;
		}
		else hi = mid-err;
	}

	return ans;
}

int main()
{
	FASTIO
	double c; cin >> c;

	double lo=err,hi=c,mid;
	double ans = hi;

	while(hi-lo>=err){
		mid = (lo+hi)/2;
		if(mid*mid + binsqrt(mid) <= c){
			ans = mid;
			lo = mid+err;
		}
		else hi = mid-err;
	}

	cout << fixed<<setprecision(6)<<ans;
}