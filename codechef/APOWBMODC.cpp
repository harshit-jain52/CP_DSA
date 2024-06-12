#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	ll a; cin >> a;
	if(a==2){
		cout << 4 << " "<<16<<endl;
	}
	else{
		ll b = 2*a, c = a*a;
		cout << b << " "<<c<<endl;
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