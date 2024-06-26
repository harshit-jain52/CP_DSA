#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int m,n; cin >> m >> n;
	ll t[n],y[n],z[n];
	for(int i=0;i<n;i++) cin >> t[i] >> z[i] >> y[i];

	ll lo=0,hi=3e6,mid;
	ll ans = hi;
	while(lo<=hi){
		mid = (lo+hi)/2;
		ll ct = 0;

		for(int i=0;i<n;i++){
			ll time=mid;
			ll tmp = min(time,t[i]*z[i]);
			ct += tmp/t[i];
			time -= tmp;

			ct += z[i]*(time/(t[i]*z[i]+y[i]));
			ll rem = time%(t[i]*z[i]+y[i]);
			if(rem>y[i]) ct+=(rem-y[i])/t[i];
		}

		if(ct>=m){
			ans=mid;
			hi=mid-1;
		}
		else lo=mid+1;
	}

	cout << ans << endl;
	ll tot=0;
	for(int i=0;i<n;i++){
		ll ct = 0;
		ll time=ans;
		ll tmp = min(time,t[i]*z[i]);
		ct += tmp/t[i];
		time -= tmp;

		ct += z[i]*(time/(t[i]*z[i]+y[i]));
		ll rem = time%(t[i]*z[i]+y[i]);
		if(rem>y[i]) ct+=(rem-y[i])/t[i];

		ct = min(ct,m-tot);
		tot+=ct;
		
		cout << ct << " ";
	}
}