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
	int n,k; cin >> n >> k;
	vector<int>p(13,0);

	for(int i=0;i<n;i++){
		int x; cin >> x;
		p[x-1]++;
	}

	vector<pii>dp(1<<13);
	dp[0]={1,0};
	
	for(int i=1; i<(1<<13); i++){
		dp[i] = {14,0};
		for(int j=0;j<13;j++){
			if((i>>j)&1){
				pii pp = dp[i^(1<<j)];
				if(pp.S+p[j] <= k) pp.S+=p[j];
				else{
					pp.F++;
					pp.S=p[j];
				}
				dp[i] = min(dp[i],pp);
			}
		}
	}

	cout << dp[(1<<13)-1].F;
}