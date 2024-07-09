#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const ll INF = 1e15;
vector<vector<ll>>dp;

void solve(){
	int n; cin >> n;
	int a[n];

	vector<int>ct(n+1,0);
	for(int i=0;i<n;i++){
		cin >> a[i];
		ct[a[i]]++;
	}

	vector<int>ctf;
	for(int i=1;i<=n;i++){
		if(ct[i]==0) continue;
		ctf.push_back(ct[i]);
	}

	int sz = ctf.size();
	dp.assign(sz+1,vector<ll>(sz+1,INF));
	dp[0][0]=0;

	for(int i=1;i<=sz;i++){
		for(int j=0;j<=sz;j++){
			dp[i][j] = min(dp[i][j],dp[i-1][j]);
			if(j>0 && dp[i-1][j-1]+ctf[i-1]<=i-j) dp[i][j] = min(dp[i][j],dp[i-1][j-1]+ctf[i-1]);
		}
	}

	int x = sz;
	for(int j=0;j<=sz;j++) if(dp[sz][j]<INF) x=sz-j;
	cout << x << endl;
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