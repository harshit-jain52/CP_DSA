#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	int k[n];

	for(int i=0;i<n;i++) cin >> k[i];

	int lcm = k[0];
	
	for(int i=1;i<n;i++){
		int g = __gcd(lcm,k[i]);
		lcm = (lcm*1LL*k[i])/g;
	}

	int sum=0;
	vector<int>x(n);

	for(int i=0;i<n;i++){
		x[i]=lcm/k[i];
		sum += x[i];
	}


	if(lcm<=sum) cout << -1;
	else{
		for(int i=0;i<n;i++) cout << x[i]<<" ";
	}
	cout << endl;
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