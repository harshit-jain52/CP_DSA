#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,k; cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	int lo=0,hi=a[n-1]-a[0], mid;
	int ans = hi;

	while(lo<=hi){
		mid = (lo+hi)/2;
		int last = a[0], ct=1;
		for(int i=1;i<n;i++){
			if(a[i]-last>=mid){
				ct++;
				last = a[i];
			}
		}
		if(ct>=k){
			ans = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}

	cout << ans;
}