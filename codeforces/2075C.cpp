#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,m; cin >> n >> m;
	int a[m];
	for(int i=0;i<m;i++) cin >> a[i];
	sort(a,a+m);
	
	ll suff[m+1];
	suff[m]=0;
	for(int i=m-1;i>=0;i--) suff[i]=suff[i+1]+min(a[i],n-1);

	ll ans = 0;
	for(int i=0;i<m-1;i++){
		int req = max(n-a[i],1);
		int j = lower_bound(a+i+1,a+m,req)-a;
		ans += suff[j]-(m-j)*1LL*(req-1);
	}

	cout << ans*2 << endl;
}

int main()
{
	FASTIO
	int t; cin >> t;
	while(t--){
		solve();
	}
}