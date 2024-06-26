#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,x,y;
	cin >> n >> x >> y;

	int m = min(x,y);
	ll lo=m,hi=n*m,mid;
	ll ans = hi;

	while(lo<=hi){
		mid = (lo+hi)/2;

		ll t = mid-m;
		if(t/x + t/y + 1 >= n){
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}

	cout << ans;
}