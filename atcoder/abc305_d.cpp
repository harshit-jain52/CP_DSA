#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; cin >> n;
	ll a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	ll pref[n];
	pref[0]=0;
	for(int i=1;i<n;i++){
		pref[i]=pref[i-1];
		if(i%2==0) pref[i] += a[i]-a[i-1];
	}

	// for(int i=0;i<n;i++) cout << pref[i]<<" ";
	// cout << endl;

	int q; cin >> q;
	while(q--){
		ll l,r; cin >> l >> r;
		ll ans = 0;

		int L = (lower_bound(a,a+n,l)-a);
		int R = (upper_bound(a,a+n,r)-a);
		
		if(L==R){
			if(L%2==0) ans += r-l;
			cout << ans << endl;
			continue;
		}

		if(L%2==0){
			ans += a[L]-l;
			L++;
		}
		R--;

		// cout << ans << endl;
		// cout << L << " "<<R<<endl;
		// cout << pref[R]-pref[L-1]<<endl;
		if(L<=R) ans += (pref[R]-pref[L-1]);
		if(R&1) ans += r-a[R];
		cout << ans << endl;
	}
}