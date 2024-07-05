#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,f,k; cin >> n >> f >> k;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	int fav = a[f-1];
	
	sort(a,a+n);
	k=n-k;
	int i1 = lower_bound(a,a+n,fav)-a;
	int i2 = upper_bound(a,a+n,fav)-a;

	if(i2<=k) cout << "NO\n";
	else if(i1>=k) cout <<"YES\n";
	else cout << "MAYBE\n";
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