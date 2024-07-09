#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;
const ll INF = 1e17;

int binpow(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = (ans*1LL*a)%M;
		a = (a*1LL*a)%M;
		b>>=1;
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	ll a[n];

	for(int i=0;i<n;i++) cin >> a[i];

	ll sum = accumulate(a,a+n,0LL);
	
	ll pref=0, mnpref=INF;
	ll k = sum;
	for(int i=0;i<n;i++){
		pref += a[i];
		mnpref = min(mnpref,pref); // find most -ve pref
		k = max(k,sum-pref+abs(pref));
	}

	if(mnpref>=0){ // no -ve pref
		cout << binpow(2,n) << endl;
		return;
	}

	int ways = 0, ctpos=0;
	pref=0;

	for(int i=0;i<n;i++){
		pref += a[i];
		if(pref==mnpref) ways = (ways + binpow(2,n-1-i+ctpos))%M;
		if(pref>=0) ctpos++;
	}

	cout << ways << endl;
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