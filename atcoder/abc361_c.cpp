#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,k;
	cin >> n >> k;

	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	sort(a,a+n);


	int ans = INT_MAX;
	int i = k, j=n-1;
	while(i>=0){
		ans = min(ans, a[j]-a[i]);
		i--; j--;
	}

	cout << ans;
}