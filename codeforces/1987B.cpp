#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	int mx=0;
	map<int,int>op;
	int ct = 0;

	for(int i=0;i<n;i++){
		if(a[i]>=mx) mx=a[i];
		else{
			op[mx-a[i]]++;
			ct++;
		}
	}

	ll ans = 0;
	ll pref = 0;
	for(auto it: op){
		// cout << it.first << " "<<it.second<<endl;
		ans += (it.first-pref)*1LL*(ct+1);
		ct -= it.second;
		pref = it.first;
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