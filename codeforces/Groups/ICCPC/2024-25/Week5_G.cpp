#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	ll ans = 0;
	ll k[n], s[m];
	for(int i=0;i<n;i++){
		cin >> k[i];
		if(i) ans += abs(k[i]-k[i-1]);
	}
	for(int i=0;i<m;i++){
		cin >> s[i];
		if(i) ans += abs(s[i]-s[i-1]);
	}
	cout << ans << endl;
}