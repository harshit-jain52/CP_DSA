#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; cin >> n;
	ll a; cin >> a;
	ll t[n];
	for(int i=0;i<n;i++) cin >> t[i];

	ll last=0;
	for(int i=0;i<n;i++){
		last = max(last,t[i]);
		last += a;
		cout << last<< endl;
	}
}