#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,q;
	cin >> n >> q;
	int a[n];
	vector<int>freq(n+1,0);

	for(int i=0;i<n;i++){
		cin >> a[i];
		freq[a[i]]++;
	}

	ll ans = 0;
	for(int i=1;i<=n;i++) ans += freq[i]*1LL*(freq[i]+1)/2;

	while(q--){
		int p,x; cin >> p >> x;
		p--;
		ans -= freq[a[p]];
		freq[a[p]]--;
		a[p]=x;
		freq[a[p]]++;
		ans += freq[a[p]];

		cout << ans << endl;
	}
}