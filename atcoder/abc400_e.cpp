#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e6+6;

vector<int>pfct(N,0);

int main()
{
	FASTIO

	vector<int>vec;
	for(int i=2;i<N;i++){
		if(pfct[i]==0){
			for(int j=2*i;j<N;j+=i) pfct[j]++;
		}
		if(pfct[i]==2) vec.push_back(i);
	}

	int q; cin >> q;
	while(q--){
		ll a; cin >> a;

		int lo=0, hi=vec.size()-1;
		ll ans=vec[lo]*vec[lo];
		while(lo<=hi){
			int mid = (lo+hi)/2;
			ll sq = vec[mid]*1LL*vec[mid];
			if(sq <= a){
				ans = sq;
				lo = mid+1;
			}
			else hi = mid-1;
		}

		cout << ans << endl;
	}
}