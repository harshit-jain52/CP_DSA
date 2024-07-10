#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool isPrime(ll num){
	if(num==1) return false;
	for(ll i=2;i*i<=num;i++) if(num%i==0) return false;
	return true;
}

void solve(){
	ll x; cin >> x;

	ll nex1=-1,nex2=-1;
	for(ll i=x;nex2==-1;i++){
		if(isPrime(i)){
			if(nex1==-1) nex1=i;
			else nex2=i;
		}
	}

	cout << nex1*nex2<< endl;
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