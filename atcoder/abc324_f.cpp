#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const double INF = 1e15;
const double err = 1e-10;

int main()
{
	FASTIO
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,pii>>>rg(n+1);

	double sumb=0;
	while(m--){
		int u,v,b,c; cin >> u >> v >> b >> c;
		rg[v].push_back({u,{b,c}});
		sumb+=b;
	}

	auto check = [&](double val)->bool{
		vector<double>dist(n+1,-INF);
		dist[1] = 0;

		for(int i=2;i<=n;i++){
			for(auto prev: rg[i]){
				dist[i] = max(dist[i],dist[prev.F]+prev.S.F-val*prev.S.S);
			}
		}

		return (dist[n]>=0);
	};

	double lo = 0, hi = sumb, ans = 0;

	while(hi-lo>err){
		double mid = (lo+hi)/2;

		if(check(mid)){
			ans = mid;
			lo = mid+err;
		}
		else hi = mid-err;
	}

	cout << fixed << setprecision(9) << ans;
}