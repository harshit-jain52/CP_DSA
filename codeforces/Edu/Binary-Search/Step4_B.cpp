#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
#define F first
#define S second
const double err = 1e-6;

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	vector<pair<pair<int,int>,int>>path;
	for(int i=0;i<m;i++){
		int a,b,c; cin >> a >> b >> c;
		path.push_back({{a,b},c});
	}

	sort(path.begin(),path.end());

	double lo = 1, hi = 100, mid;
	double ans = hi;

	while(hi-lo>=err){
		mid = (lo+hi)/2;

		vector<double>dp(n+1,1e9);
		dp[1] = 0;

		for(int i=0;i<m;i++){
			dp[path[i].F.S] = min(dp[path[i].F.S],dp[path[i].F.F]+path[i].S-mid);
		}

		if(dp[n]<=0){
			ans = mid;
			hi = mid-err;
		}
		else lo=mid+err;
	}

	vector<double>dp(n+1,1e9);
	vector<int>par(n+1,0);
	dp[1] = 0;
	// cout << ans << endl;
	for(int i=0;i<m;i++){
		int a = path[i].F.F, b = path[i].F.S, c = path[i].S;
		if(dp[b]>dp[a]+c-ans){
			dp[b]=dp[a]+c-ans;
			par[b]=a;
		}
	}

	int cur = n;
	vector<int>way;
	while(cur!=0){
		way.push_back(cur);
		cur = par[cur];
	}

	int k = way.size() - 1;
	cout << k << endl;
	for(int i=k;i>=0;i--) cout << way[i] << " ";
}