#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,m; cin >> n >> m;
	ll a[n], b[m];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];

	int x = a[0];
	sort(a,a+n);
	sort(b,b+m);
	reverse(upper_bound(b,b+m,x),b+m);
	
	for(int k=1;k<=m;k++){
		ll ans=0;
		for(int j=k;j<=m;j+=k){
			ans++;
			if(b[j-1]>x) ans+=a+n-lower_bound(a,a+n,b[j-1]);
		}
		cout << ans << " ";
	}
	cout << endl;
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