#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

ll solve(){
	int n,k; cin >> n >> k;
	vector<ll>a(n);
	for(int i=0;i<n;i++) cin >> a[i];

	if(k==1){
		ll ans = a[0]+a[n-1];
		for(int i=1;i<n-1;i++) ans = max(ans,a[i]+max(a[0],a[n-1]));
		return ans;
	}

	sort(a.rbegin(),a.rend());
	ll ans = 0;
	for(int i=0;i<=k;i++) ans += a[i];
	return ans;
}

int main()
{
	FASTIO
	int t; cin >> t;
	while(t--){
		cout << solve() << endl;
	}
}