#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int binpow(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = (ans*1LL*a)%M;
		a = (a*1LL*a)%M;
		b >>= 1;
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	ll a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	ll sum = accumulate(a,a+n,0LL);
	sum %= M;

	int p = 0;
	for(int i=0;i<n;i++){
		p += (a[i]*1LL*(sum-a[i]+M))%M;
		p %= M;
	}

	int q = binpow((n*1LL*(n-1))%M,M-2);
	cout << (p*1LL*q)%M << endl;
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