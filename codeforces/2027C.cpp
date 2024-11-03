#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
#define F first
#define S second
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<pair<ll,ll>>vec(n);
	for(int i=0;i<n;i++){
		ll a; cin >> a;
		vec[i].F = a+i;
		vec[i].S = i;
	}

	sort(vec.begin(),vec.end());
	vector<ll>dp(n+1,n);

	set<ll>st;
	st.insert(n);

	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(st.find(vec[i-1].F)!=st.end()){
			ll len = vec[i-1].F+vec[i-1].S;
			st.insert(len);
			dp[i]=max(dp[i],len);
		}
	}

	cout << dp[n] << endl;
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