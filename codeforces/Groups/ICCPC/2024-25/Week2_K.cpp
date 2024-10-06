#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int>a(n),pos(n+1);

	for(int i=0;i<n;i++){
		cin >> a[i];
		pos[a[i]] = i;
	}

	int m = 1;
	for(int i=2;i<=n;i++){
		m += (pos[i]>pos[i-1]);
	}

	cout << m << endl;
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