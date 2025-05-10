#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

struct prob{
	int s, c;
	double p;
	prob(int _s, int _c, int _p): s(_s), c(_c), p(_p*1.0/100) {}
};

vector<vector<double>>dp;

int main()
{
	FASTIO
	int n,x; cin >> n >> x;
	dp.assign(1<<n,vector<double>(x+1,0));
	vector<prob>data;

	for(int i=0;i<n;i++){
		int s,c,p;
		cin >> s >> c >> p;
		data.emplace_back(s,c,p);
	}

	for(int mask=1;mask<(1<<n);mask++){
		for(int yen=0;yen<=x;yen++){
			for(int bit=0;bit<n;bit++){
				if((mask>>bit)&1){
					if(yen>=data[bit].c){
						dp[mask][yen] = max(dp[mask][yen],
						data[bit].p*(data[bit].s+dp[mask^(1<<bit)][yen-data[bit].c])
						+ (1-data[bit].p)*dp[mask][yen-data[bit].c]);
					}
				}
			}
		}
	}

	double ans = 0;
	for(int mask=1;mask<(1<<n);mask++) ans = max(ans,dp[mask][x]);
	cout << setprecision(20) << ans;
}