#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	string burg; cin >> burg;

	vector<int>req(3,0);
	for(int i=0;i<burg.size();i++){
		req[0] += (burg[i]=='B');
		req[1] += (burg[i]=='S');
		req[2] += (burg[i]=='C');
	}

	int nb,ns,nc; cin >> nb >> ns >> nc;
	int pb,ps,pc; cin >> pb >> ps >> pc;
	ll r; cin >> r;

	ll lo=0,hi=1e13,mid;
	ll ans = lo;

	while(lo<=hi){
		mid = (lo+hi)/2;

		ll mon=0;
		mon += pb*max(0LL,mid*req[0]-nb);
		mon += ps*max(0LL,mid*req[1]-ns);
		mon += pc*max(0LL,mid*req[2]-nc);
		if(mon<=r){
			ans = mid;
			lo=mid+1;
		}
		else hi = mid-1;
	}

	cout << ans;
}