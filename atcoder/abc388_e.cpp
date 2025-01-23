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
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	sort(a,a+n);

	int lo=1,hi=n/2,mid;
	int ans=0;

	while(lo<=hi){
		mid = (lo+hi)/2;

		int i=0,j=n-mid;

		while(j<n){
			if(a[j]/2 >= a[i]) i++;
			j++;
		}

		if(i==mid){
			ans = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}

	cout << ans << endl;
}