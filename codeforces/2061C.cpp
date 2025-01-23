#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

void solve(){
	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	vector<vector<int>>dp(n,vector<int>(2,0));
	
	dp[0][0]=1;
	dp[0][1]=(a[0]==0);

	for(int i=1;i<n;i++){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = ((i>1)?((a[i]==(a[i-2]+1))*dp[i-1][0]):(a[i]==1));
		if(a[i]==a[i-1]) dp[i][1] = (dp[i][1]+dp[i-1][1])%M;
	}

	cout << (dp[n-1][0]+dp[n-1][1])%M << endl;
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