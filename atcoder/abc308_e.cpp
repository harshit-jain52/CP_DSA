#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	string s; cin >> s;
	
	ll dp[2][6];
	memset(dp,0,sizeof(dp));
	/*
	0-0
	1-1
	2-2
	3-0,1
	4-0,2
	5-1,2
	*/
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='M'){
			dp[0][a[i]]++;
		}
		else if(s[i]=='E'){
			if(a[i]==0){
				dp[1][0] += dp[0][0];
				dp[1][3] += dp[0][1];
				dp[1][4] += dp[0][2];
			}
			else if(a[i]==1){
				dp[1][1] += dp[0][1];
				dp[1][3] += dp[0][0];
				dp[1][5] += dp[0][2];
			}
			else{
				dp[1][2] += dp[0][2];
				dp[1][4] += dp[0][0];
				dp[1][5] += dp[0][1];
			}
		}
		else{
			if(a[i]==0){
				ans += 1*(dp[1][0]+dp[1][2]+dp[1][4]);
				ans += 2*(dp[1][1]+dp[1][3]);
				ans += 3*(dp[1][5]);
			}
			else if(a[i]==1){
				ans += 2*(dp[1][0]+dp[1][3]);
				ans += 3*(dp[1][4]);
			}
			else{
				ans += 1*(dp[1][0]+dp[1][4]);
				ans += 3*(dp[1][3]);
			}
		}
	}

	cout << ans;
}