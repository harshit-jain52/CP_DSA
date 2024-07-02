#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,m; cin >> n >> m;
	int a[n][m];

	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int mx = INT_MIN;
			if(i>0) mx = max(mx,a[i-1][j]);
			if(j>0) mx = max(mx,a[i][j-1]);
			if(i<n-1) mx = max(mx,a[i+1][j]);
			if(j<m-1) mx = max(mx,a[i][j+1]);

			if(mx!=INT_MIN && mx<a[i][j]) a[i][j]=mx;

			cout << a[i][j]<<" ";
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