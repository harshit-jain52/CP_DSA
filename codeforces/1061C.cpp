#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e6+1;
const int INF = 1e7;
vector<vector<int>>divis(N);

void divisors(){
	for(int i=1;i<N;i++) divis[i].push_back(1);
    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
            divis[j].push_back(i);
}

int main()
{
	FASTIO
	divisors();
	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	vector<int>dp(n+1,0), ndp(n+1,0);
	dp[0]=1;

	for(int i=0;i<n;i++){
		for(int d: divis[a[i]]){
			if(d>n) break;
			ndp[d] = (dp[d]+dp[d-1])%M;
		}
		for(int d: divis[a[i]]){
			if(d>n) break;
			dp[d] = ndp[d];
		}
	}

	int ans = 0;
	for(int i=1;i<=n;i++) ans = (ans+dp[i])%M;
	cout << ans;
}