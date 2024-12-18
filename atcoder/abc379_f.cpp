#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,q; cin >> n >> q;
	int h[n]; vector<vector<pii>>qu(n);
	for(int i=0;i<n;i++) cin >> h[i];
	for(int i=0;i<q;i++){
		int l,r; cin >> l >> r;
		l--; r--;
		qu[l].push_back({i,r});
	}

	vector<int>st;
	vector<int>ans(q);
	for(int l=n-1;l>=0;l--){
		for(pii pp: qu[l]){
			int r = pp.S, i = pp.F;
			ans[i] = lower_bound(st.begin(),st.end(),-r) - st.begin();
		}
		while(st.size() && h[-st.back()]<h[l]) st.pop_back();
		st.push_back(-l);
	}

	for(int i=0;i<q;i++) cout << ans[i]<< endl;;
}