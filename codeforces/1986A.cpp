#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int x1,x2,x3; cin >> x1 >> x2 >> x3;

	int ans = 30;
	for(int i=1;i<=10;i++){
		ans = min(ans,abs(i-x1)+abs(i-x2)+abs(i-x3));
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