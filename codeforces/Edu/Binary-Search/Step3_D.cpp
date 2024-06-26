#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
#define F first
#define S second
typedef pair<int,int> pii;

int main()
{
	FASTIO
	int n,m,d; cin >> n >> m >> d;
	vector<pair<pii,int>>vec;
	for(int i=0;i<m;i++){
		int a,b,c; cin >> a>> b >> c;
		vec.push_back({{a,b},c});
	}

	sort(vec.begin(),vec.end());
	ll lo=0,hi=1e9,mid;
	ll ans = -1;

	while(lo<=hi){
		mid = (lo+hi)/2;
		vector<pii>edg;
		for(int i=0;i<m;i++) if(vec[i].S<=mid) edg.push_back(vec[i].F);

		bool flag = true;
		if(edg.size()==0 || edg[0].F!=1) flag = false;
		else{
			vector<int>dp(n+1,1e7);
			dp[1]=0;
			for(int i=0;i<edg.size();i++){
				dp[edg[i].S] = min(dp[edg[i].S],1+dp[edg[i].F]);
			}

			if(dp[n]>d) flag = false;
		}

		if(flag){
			ans = mid;
			hi=mid-1;
		}
		else lo = mid+1;
	}

	if(ans==-1) cout << -1;
	else{
		vector<pii>edg;
		for(int i=0;i<m;i++) if(vec[i].S<=ans) edg.push_back(vec[i].F);

		vector<int>dp(n+1,1e7);
		vector<int>par(n+1,0);
		dp[1]=0;
		for(int i=0;i<edg.size();i++){
			if(dp[edg[i].S]>1+dp[edg[i].F]){
				dp[edg[i].S]=1+dp[edg[i].F];
				par[edg[i].S] = edg[i].F;
			}
		}

		cout << dp[n] << endl;
		int cur = n;
		stack<int>st;
		while(cur!=0){
			st.push(cur);
			cur = par[cur];
		}
		while(!st.empty()){
			cout << st.top()<<" ";
			st.pop();
		}
	}
}