#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,k; cin >> n>>k;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	ll tot = 0;
	for(int i=1;i<n;i++) tot += abs(a[i]-a[i-1]);

	ll ans = tot;

	for(int i=0;i<n;i++){
		ll tmp = tot;
		if(i>0) tmp -= abs(a[i]-a[i-1]);
		if(i<n-1) tmp -= abs(a[i+1]-a[i]);

		ll tmp1 = tmp;
		if(i>0) tmp1 += abs(k-a[i-1]);
		if(i<n-1) tmp1+= abs(a[i+1]-k);

		ans = max(ans,tmp1);

		if(i>0) tmp += abs(1-a[i-1]);
		if(i<n-1) tmp+= abs(a[i+1]-1);

		ans = max(ans,tmp);
	}

	cout << ans<<endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}