#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2001;
#define F first
#define S second

int dp[N][N];
int a[N];
int n,h,l,r;

inline bool good(int x){
	return (x>=l && x<=r);
}

int func(int i, int hr){
	if(i==n) return 0;
	if(dp[i][hr]!=-1) return dp[i][hr];

	int ans = 0;
	pair<int,int> ch = {(hr+a[i])%h, (hr+a[i]-1+h)%h};
	ans = max(ans, good(ch.F)+func(i+1,ch.F));
	ans = max(ans, good(ch.S)+func(i+1,ch.S));
	return dp[i][hr] = ans;
}

int main()
{
	FASTIO
	memset(dp,-1,sizeof(dp));
	cin >> n >> h >> l >> r;
	for(int i=0;i<n;i++) cin >> a[i];

	cout << func(0,0);
}