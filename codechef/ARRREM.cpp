#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	ll a[n];

	for(int i=0;i<n;i++) cin >> a[i];
	
	int ans = n;
	for(int x=0;x<=31;x++){
		ll tmp = 0;
		ll num = ((1LL<<x)-1);
		int ct = n;

		for(int i=0;i<n;i++){
			if(a[i]>num) continue;
			ct--;
			tmp |= a[i];
		}

		if(tmp==num) ans = min(ans,ct);
	}

	cout << ans << endl;
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