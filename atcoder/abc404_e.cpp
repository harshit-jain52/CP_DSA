#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int INF = 1e7;

int main()
{
	FASTIO
	int n; cin >> n;
	vector<int>c(n),a(n),prev(n);

	int p=0;
	for(int i=1;i<n;i++) cin >> c[i];
	for(int i=1;i<n;i++){
		prev[i]=p;
		cin >> a[i];
		if(a[i]==1) p=i;		
	}

	// for(int i=1;i<n;i++) cout << prev[i] << " ";

	vector<int>dp(n+1,INF);
	dp[0]=0;

	for(int i=1;i<=p;i++){
		int st = max(prev[i],i-c[i]);
		for(int j=st;j<i;j++){
			dp[i]=min(dp[i],1+dp[j]);
		}
	}

	// for(int i=0;i<=n;i++) cout << dp[i] << endl;
	cout << dp[p] << endl;
}