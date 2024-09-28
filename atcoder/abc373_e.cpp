#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
#define F first
#define S second

int main()
{
	FASTIO
	int m,n; ll k;
	cin >> n >> m >> k;

	vector<ll>a(n);
	vector<pair<ll,int>>vec;
	ll tot=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		tot += a[i];
		vec.push_back({a[i],i});
	}

	if(m==n){
		for(int i=0;i<n;i++) cout << 0 << " ";
		return 0;
	}

	sort(vec.begin(),vec.end());
	vector<int>pos(n);
	vector<ll>prefsum(n+1);
	prefsum[0]=0;

	for(int i=0;i<n;i++){
		pos[vec[i].S]=i;
		prefsum[i+1] = prefsum[i]+vec[i].F;
	}


	for(int i=0;i<n;i++){
		ll lo=0, hi = k-tot;
		ll ans = -1;

		// cout << endl << i << endl;

		while(lo<=hi){
			ll mid = (lo+hi)/2;
			ll left = k-tot-mid;
			ll vot = a[i]+mid;

			int idx = upper_bound(vec.begin(),vec.end(),make_pair(vot,n))-vec.begin();
			bool flag = false;

			// cout << mid << " " << left << " " << idx << endl;

			if(n-idx<m){
				ll rest = prefsum[idx]-prefsum[n-m];
				if(pos[i]>=n-m) rest = rest-a[i]+vec[n-m-1].F;

				// cout << "--"<<rest << endl;
				ll req = (idx-(n-m))*(vot+1)-rest;
				// cout << "---"<<req << endl;
				if(req>left) flag = true;
			}

			if(flag){
				ans = mid;
				hi=mid-1;
			}
			else lo=mid+1;
		}

		cout << ans << " ";
	}
	
}