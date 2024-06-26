#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const double err = 1e-7;

bool check(int a[], int b[], int n, double x, int k){
	vector<double>vec;
	for(int i=0;i<n;i++) vec.push_back(a[i]-x*b[i]);
	sort(vec.begin(),vec.end());

	double sum=0;
	for(int i=n-1;i>=n-k;i--) sum += vec[i];

	return (sum>=0);
}

int main()
{
	FASTIO
	int n,k; cin >> n >> k;
	int a[n], b[n];
	for(int i=0;i<n;i++) cin >> a[i] >> b[i];

	double lo = 0, hi = 1e5, mid;
	double ans = 0;

	while(hi-lo>=err){
		mid = (lo+hi)/2;

		if(check(a,b,n,mid,k)){
			ans = mid;
			lo = mid+err;
		}
		else hi = mid-err;
	}

	cout << fixed << setprecision(6) << ans;
}