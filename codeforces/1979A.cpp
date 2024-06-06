#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	int a[n];

	int minn = INT_MAX;
	for(int i=0;i<n;i++) cin >> a[i];

	for(int i=1;i<n;i++) minn = min(minn,max(a[i],a[i-1]));

	cout << minn-1<<endl;
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