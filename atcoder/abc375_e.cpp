#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int INF = 1e5;

int dp[101][1501][1501];
int n, tot, a[101], b[101];

int func(int i, int x, int y){
	if(i==n){
		if(x==y && 3*x==tot) return 0;
		return INF;
	}

	if(dp[i][x][y]!=-1) return dp[i][x][y];

	int ans = INF;
	switch(a[i]){
	case 1:
		ans = min(ans, func(i+1,x+b[i],y));
		ans = min(ans, 1+func(i+1,x,y+b[i]));
		ans = min(ans, 1+func(i+1,x,y));
		break;
	case 2:
		ans = min(ans, 1+func(i+1,x+b[i],y));
		ans = min(ans, func(i+1,x,y+b[i]));
		ans = min(ans, 1+func(i+1,x,y));
		break;
	default:
		ans = min(ans, 1+func(i+1,x+b[i],y));
		ans = min(ans, 1+func(i+1,x,y+b[i]));
		ans = min(ans, func(i+1,x,y));
	}

	return dp[i][x][y] = ans;
}

int main()
{
	FASTIO
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i] >> b[i];

	tot = accumulate(b,b+n,0);
	if(tot%3!=0){
		cout << -1;
		return 0;
	}

	memset(dp,-1,sizeof(dp));

	int ans = func(0,0,0);

	cout << ((ans<INF)?ans:-1);
}