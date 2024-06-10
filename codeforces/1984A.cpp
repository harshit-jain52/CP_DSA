#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	if(a[0]==a[n-1]) cout << "NO\n";
	else{
		cout << "YES\n";
		for(int i=0;i<n;i++){
			if(i==1) cout << 'B';
			else cout << 'R';
		}
		cout << endl;
	}
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