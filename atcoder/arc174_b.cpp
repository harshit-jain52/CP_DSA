#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	ll a[6], p[6];
	ll req = 0, tot = 0;;
	for(int i=1;i<=5;i++){
		cin >> a[i];
		req += a[i]*3;
		tot += a[i]*i;
	}
	for(int i=1;i<=5;i++) cin >> p[i];

	if(tot>=req){
		cout << 0 << endl;
		return;
	}

	ll diff = req-tot;

	if(p[5]>2*p[4]){
		cout << diff*p[4] << endl;
	}
	else{
		cout << (diff/2)*p[5] + (diff%2)*(min(p[5],p[4]))<<endl;
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