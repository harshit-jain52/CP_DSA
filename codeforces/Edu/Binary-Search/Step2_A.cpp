#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	ll w,h,n; cin >> w >> h >> n;

	ll lo=1,hi=n*max(h,w),mid;
	ll ans = hi;

	while(lo<=hi){
		mid = (lo+hi)/2;
		ll num1 = mid/w, num2 = mid/h;
		if(num2!=0 && num1>=LLONG_MAX/num2 || num1*num2>=n){
			ans = mid;
			hi=mid-1;
		}
		else lo = mid+1;
	}

	cout << ans;
}