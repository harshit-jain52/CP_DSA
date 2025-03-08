#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const ll INF = 1e15;

struct Query{
	int idx;
	int r;
	ll x;
	Query(){idx=r=x=-1;}
	bool operator <(Query other){
		return r<other.r;
	}
};

int main()
{
	FASTIO
	int n,q; cin >> n >> q;
	vector<ll>a(n);
	vector<Query>qu(q);

	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<q;i++){
		cin >> qu[i].r >> qu[i].x;
		qu[i].idx = i;
		qu[i].r--;
	}

	sort(qu.begin(),qu.end());
	// for(int i=0;i<q;i++) cout << qu[i].r << endl;

	vector<ll>dp(n+1,INF);
	dp[0]= -INF;

	vector<int>ans(q);
	int j=0;
	for(int i=0;i<q;i++){
		while(j<=qu[i].r){
			int len = lower_bound(dp.begin(),dp.end(),a[j]) - dp.begin();
			dp[len] = a[j];
			j++;
		}
		ans[qu[i].idx] = upper_bound(dp.begin(),dp.end(),qu[i].x) - dp.begin() - 1;
	}

	for(int i=0;i<q;i++) cout << ans[i] << endl;
}