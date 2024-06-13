#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	ll n,a,b;
	cin >> n >> a >> b;

	ll rank=0, arr[n+1];
	for(ll i=1;i<=n;i++) arr[i] = (a*i)/b;

	for(ll i=1;i<=n;i++){
		for(ll j=2*i;j<=n;j+=i){
			arr[j]-=arr[i];
		}
		rank += arr[i];
	}

	cout << rank+1<<endl;
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