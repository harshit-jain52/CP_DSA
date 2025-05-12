#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; cin >> n;
	vector<string>grid(n);
	for(int i=0;i<n;i++) cin >> grid[i];

	vector<vector<bool>>dp(n,vector<bool>(n,false));
	dp[0][0]=true;

	for(int len=0;len<2*n-2;len++){
		char mn = 'Z';
		for(int i=max(0,len-n+1);i<=min(len,n-1);i++){
			int j = len-i;
			if(dp[i][j]) mn = min(mn,grid[i][j]);
		}
		cout << mn;
		for(int i=max(0,len-n+1);i<=min(len,n-1);i++){
			int j = len-i;
			if(dp[i][j] && grid[i][j]==mn){
				if(i+1<n) dp[i+1][j]=true;
				if(j+1<n) dp[i][j+1]=true;
			}
		}
	}

	cout << grid[n-1][n-1];
}