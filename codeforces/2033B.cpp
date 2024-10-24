#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	ll a[n][n];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];

	ll ans = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]<0){
				int tmp = -a[i][j];
				ans += tmp;
				for(int k=-n;k<=n;k++){
					int x=i+k,y=j+k;
					if(x>=0 && y>=0 && x<n && y<n) a[x][y]+=tmp;
				}
			}
		}
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