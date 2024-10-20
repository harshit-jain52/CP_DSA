#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
const int M = 1e9+7;

void solve(){
	int n,k; cin >> n >> k;
	vector<pll>vec(n);
	
	for(int i=0;i<n;i++) cin >> vec[i].F;
	for(int i=0;i<n;i++) cin >> vec[i].S;

	
	sort(vec.begin(),vec.end());
	
	ll currsum=0;
	ll ans = 1e18;
	priority_queue<ll>pq;

	for(int i=0;i<n;i++){
		currsum += vec[i].S;
		if(i>=k-1){
			if(i>=k){
				currsum -= pq.top();
				pq.pop();
			}
			ans = min(ans,vec[i].F*currsum);
		}
		pq.push(vec[i].S);
	}
	cout << ans << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}