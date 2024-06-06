#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int x,y;
	cin >> x >> y;

	for(int bit=0; (1<<bit)<=max(x,y);bit++){
		if(((x>>bit)&1)==((y>>bit)&1)) continue;

		cout << (1<<bit)<<endl;
		return;
	}
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