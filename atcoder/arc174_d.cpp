#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
ll pow10[19];

void solve(){
	ll n; cin >> n;
	ll ans = 0;
	if(n>=1) ans++;

	for(int i=2;i<=18;i+=2){
		if(n>=pow10[i]-2*pow10[i/2]) ans++;
		if(n>=pow10[i]-pow10[i/2]) ans += min(n,pow10[i]-1)-(pow10[i]-pow10[i/2])+1;
		if(n>=pow10[i]) ans += min(n,pow10[i]+pow10[i/2]-1)-pow10[i]+1;
	}
	
	cout << ans << endl;
}

int main()
{
	FASTIO
	pow10[1]=10;
	for(int i=2;i<19;i++) pow10[i]=10*pow10[i-1];

	int t;
	cin >> t;
	while(t--){
		solve();
	}
}