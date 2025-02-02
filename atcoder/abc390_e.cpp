#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 5005;

ll dp[N][N][3];

int main()
{
	FASTIO
	memset(dp,0,sizeof(dp));
	int n,x; cin >> n >> x;
	vector<tuple<int,ll,int>>vec;
	vec.emplace_back(0,0,0);
	for(int i=0;i<n;i++){
		int v,a,c; cin >> v >> a >> c;
		vec.emplace_back(v-1,a,c);
	}

	// for(int i=1;i<=n;i++){
	// 	auto [v,a,c] = vec[i];
	// 	cout << v << " " << a << " " << c << endl;
	// }

	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			for(int k=0;k<3;k++){
				dp[i][j][k] = dp[i-1][j][k];
				auto [v,a,c] = vec[i];
				if(v==k && j>=c) dp[i][j][k] = max(dp[i][j][k],a+dp[i-1][j-c][k]);
			}
		}
	}

	ll ans = 0;
	for(int i=0;i<=x;i++){
		for(int j=0;j<=x-i;j++){
			int k = x-i-j;
			if(k<0) continue;
			ans = max(ans,min({dp[n][i][0],dp[n][j][1],dp[n][k][2]}));
		}
	}
	cout << ans;
}