#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
const int M = 1e9+7;

void solve(){
	int n,k; cin >> n >> k;
	ll a[n], b[n];
	set<ll>st;

	for(int i=0;i<n;i++){
		cin >> a[i];
		st.insert(a[i]);
	}

	for(int i=0;i<n;i++){
		cin >> b[i];
		st.insert(b[i]);
	}

	sort(a,a+n);
	sort(b,b+n);
	
	ll ans = 0;
	for(ll p: st){
		int tot = b+n-lower_bound(b,b+n,p);
		int neg = tot - (a+n-lower_bound(a,a+n,p));
		if(neg<=k) ans=max(ans,p*tot);
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