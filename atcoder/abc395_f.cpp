#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool check(vector<ll>&u,vector<ll>&d,ll h,ll x){
	int n = u.size();
	ll l = max(h-d[0],0LL);
	ll r = u[0];

	if(l>r) return false;

	for(int i=1;i<n;i++){
		l = max({h-d[i],0LL,l-x});
		r = min(u[i],r+x);
		if(l>r) return false;
	}
	return true;
}

int main()
{
	FASTIO
	int n; ll x; cin >> n >> x;
	vector<ll>u(n),d(n);

	ll lo=0,hi=1e18,mid;
	for(int i=0;i<n;i++){
		cin >> u[i] >> d[i];
		hi = min(hi,u[i]+d[i]);
	}

	ll ans = lo;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(check(u,d,mid,x)){
			ans = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}

	// cout << ans << " ";
	ll cost=0;
	for(int i=0;i<n;i++) cost += (u[i]+d[i]-ans);
	cout << cost << endl;
}