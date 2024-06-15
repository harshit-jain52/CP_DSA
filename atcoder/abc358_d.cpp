#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,m;
	cin >> n >> m;

	ll a[n],b[m];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];

	sort(a,a+n);
	sort(b,b+m);

	ll cost  = 0;

	int i=0,j=0;

	while(i<n && j<m){
		if(a[i]>=b[j]){
			cost += a[i];
			i++;
			j++;
		}
		else i++;
	}

	if(j==m) cout << cost;
	else cout << -1;
}