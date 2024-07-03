#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int>ct(n+1,0);

	for(int i=0;i<n;i++){
		int a; cin >> a;
		ct[a]++;
	}

	ll ans = INT_MAX;
	for(int i=1;i<=n;i++){
		ans = min(ans,(n-ct[i])*1LL*i);
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