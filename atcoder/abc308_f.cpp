#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,m;
	cin >> n >> m;
	ll p[n], l[m], d[m];
	for(int i=0;i<n;i++) cin >> p[i];
	for(int i=0;i<m;i++) cin >> l[i];
	for(int i=0;i<m;i++) cin >> d[i];

	vector<int>vec(m);
	for(int i=0;i<m;i++) vec[i]=i;

	sort(vec.begin(),vec.end(),[&](int i, int j){
		if(d[i]!=d[j]) return d[i]>d[j];
		return l[i]<l[j];
	});

	multiset<ll>ms;
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans += p[i];
		ms.insert(p[i]);
	}

	for(int i=0;i<m;i++){
		int idx = vec[i];
		auto it = ms.lower_bound(l[idx]);
		if(it==ms.end()) continue;
		ans -= d[idx];
		ms.erase(it);
	}

	cout << ans;
}