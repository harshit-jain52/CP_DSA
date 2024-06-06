#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

ll a[N], dp[N][2];
vector<int>g[N];

void dfs(int v){
	if(g[v].size()==0){
		dp[v][0]=0;
		dp[v][1]=a[v];
		return;
	}

	dp[v][0]=0;
	dp[v][1]=0;

	ll tmp1 = 0;
	vector<ll>vec;
	for(int ch: g[v]){
		dfs(ch);
		tmp1 += dp[ch][0];
		vec.push_back(dp[ch][0]-dp[ch][1]);
	}

	sort(vec.begin(),vec.end());
	
	ll tmp2 = tmp1;
	tmp2-=vec[0];
	dp[v][0]=tmp1;
	dp[v][1]=tmp2;

	for(int i=1;i<vec.size();i+=2){
		tmp1 -= (vec[i]+vec[i-1]);
		dp[v][0]=max(dp[v][0],tmp1);
	}

	for(int i=2;i<vec.size();i+=2){
		tmp2 -= (vec[i]+vec[i-1]);
		dp[v][1]=max(dp[v][1],tmp2);
	}

	dp[v][1] = max(dp[v][1],dp[v][0]+a[v]);
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		int p; cin >> p >> a[i];
		if(p!=-1) g[p].push_back(i);
	}

	dfs(1);
	cout << max(dp[1][0],dp[1][1])<<endl;
}