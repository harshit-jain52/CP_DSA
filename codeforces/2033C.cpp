#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];

	int ans = 0;
	int i=0,j=n-1;
	while(i<j-1){
		ans += min((a[i]==a[i+1])+(a[j]==a[j-1]),(a[j]==a[i+1])+(a[i]==a[j-1]));
		i++; j--;
	}

	if(n%2==0) ans += (a[n/2-1]==a[n/2]);
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