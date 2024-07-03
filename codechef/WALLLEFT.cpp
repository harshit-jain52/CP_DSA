#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	ll n,k,h;
	cin >> n >> k >> h;

	ll ct = 0;
	for(int a=1;a<=n;a++){
		if(a>=h){
			ct += n;
			continue;
		}

		ll x = (h-a)/(k-1);
		ll rem = (h-a)%(k-1);
		int blim = min(n,a - x - (rem!=0));
		blim = max(blim,0);
		ct += blim;
	}

	cout << ct << endl;
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