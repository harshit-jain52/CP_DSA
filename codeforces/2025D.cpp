#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<vector<int>>sct,ict;
vector<vector<int>>dp;

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	int r[n];
	sct.resize(m+1); ict.resize(m+1);

	for(int i=0;i<n;i++) cin >> r[i];

	vector<int>stmp(m+1,0), itmp(m+1,0);

	int idx=m;
	for(int i=n-1;i>=0;i--){
		if(r[i]==0){
			sct[idx]=stmp;
			ict[idx]=itmp;
			idx--;
			stmp.assign(m+1,0);
			itmp.assign(m+1,0);
		}
		else if(r[i]>0) itmp[r[i]]++;
		else stmp[-r[i]]++;
	}

	sct[0]=vector<int>(m+1,0);
	ict[0]=vector<int>(m+1,0);

	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			sct[i][j]+=sct[i][j-1];
			ict[i][j]+=ict[i][j-1];
		}
	}

	dp.assign(m+1,vector<int>(m+1,0));
	for(int i=1;i<=m;i++){
		for(int j=0;j<=i;j++){
			int x=j,y=i-j;
			dp[i][x] = ict[i][x]+sct[i][y]+max(dp[i-1][x],((x>0)?dp[i-1][x-1]:0));
		}
	}

	int ans = 0;
	for(int j=0;j<=m;j++) ans = max(ans,dp[m][j]);
	cout << ans << endl;
}