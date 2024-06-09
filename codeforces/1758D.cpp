#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	int ans[n];

	int i=0,j=n-1;
	int l=3*n, r = 5*n;

	if(n&1) ans[n/2]=4*n;
	while(i<j){
		ans[i++]=l;
		ans[j--]=r;
		l++; r--;
	}

	for(int k=0;k<n;k++) cout << ans[k]<<" ";
	cout << endl;
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