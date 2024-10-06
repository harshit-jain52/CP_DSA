#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	string s; cin >> s;

	ll ans = 0;
	int flag = 0;

	for(int i=n-1;i>=0;i--){
		if(s[i]=='0') flag++;
		else if(flag){
			ans += (i+1);
			flag--;
		}
		else flag++;
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