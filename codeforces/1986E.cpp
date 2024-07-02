#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
#define F first
#define S second

void solve(){
	int n,k; cin >> n >> k;
	ll a[n];
	map<int,vector<int>>modk;

	for(int i=0;i<n;i++) {
		cin >> a[i];
		modk[a[i]%k].push_back(a[i]);
	}

	int oddct=0;
	for(auto it: modk){
		if(it.S.size()%2==1) oddct++;
	}

	if(oddct>1){
		cout << -1 << endl;
		return;
	}

	ll ans = 0;
	for(auto it: modk){
		sort(it.S.begin(),it.S.end());
		int sz = it.S.size();
		ll tmp = 0;
		for(int i=1;i<sz;i+=2){
			tmp += (it.S[i]-it.S[i-1])/k;
		}
		if(sz&1){
			ll pref=0,suff=0;
			for(int i=sz-1;i>0;i-=2) suff += (it.S[i]-it.S[i-1])/k;
			for(int i=0;i<sz-2;i+=2){
				tmp = min(tmp,pref+suff);
				pref += (it.S[i+1]-it.S[i])/k;
				suff -= (it.S[i+2]-it.S[i+1])/k;
			}
		}
		ans += tmp;
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