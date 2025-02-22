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

	ll p[n], s[n];
	p[0]=max(0LL,a[0]);
	s[n-1]=max(0LL,-a[n-1]);

	for(int i=1;i<n;i++){
		p[i]=p[i-1]+max(0LL,a[i]);
		s[n-1-i]=s[n-i]+max(0LL,-a[n-1-i]);
	}

	ll mx=0;
	for(int i=0;i<n;i++) mx=max(mx,p[i]+s[i]);
	cout << mx << endl;
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