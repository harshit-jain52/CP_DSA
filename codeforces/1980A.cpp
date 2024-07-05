#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int>ct(7,0);

	string a; cin >> a;
	for(int i=0;i<n;i++) ct[a[i]-'A']++;

	int ans = 0;
	for(int i=0;i<7;i++) ans += max(0,m-ct[i]);
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