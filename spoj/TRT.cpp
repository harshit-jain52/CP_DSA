#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e3+3;

ll dp[N][N];
ll v[N];
int n;

ll func(int l, int r){
	int age = (n-(r-l));
	if(age==n+1) return 0;

	if(dp[l][r]==-1) dp[l][r] = max(age*v[l]+func(l+1,r),age*v[r]+func(l,r-1));
	return dp[l][r];
}

int main()
{
	FASTIO
	memset(dp,-1,sizeof(dp));
	cin >> n;
	for(int i=0;i<n;i++) cin >> v[i];
	cout << func(0,n-1);
}