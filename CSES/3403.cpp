#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<vector<int>>dp;

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	ll a[n], b[m];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];

	dp.assign(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}

	cout << dp[n][m] << endl;

	int i=n,j=m;
	stack<int>st;
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			st.push(a[i-1]);
			i--; j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]) i--;
			else j--;
		}
	}

	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}