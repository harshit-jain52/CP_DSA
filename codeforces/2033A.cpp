#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	bool flag = 0;
	int x = 0;
	int num=1;
	while(abs(x)<=n){
		if(!flag) x -= 2*num-1;
		else x += 2*num -1;

		flag = !flag;
		num++;
	}

	if(flag) cout << "Sakurako\n";
	else cout << "Kosuke\n";
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