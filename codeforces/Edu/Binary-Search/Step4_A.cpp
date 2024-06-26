#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const double err = 1e-6;

int main()
{
	FASTIO
	int n,d; cin >> n >> d;
	int a[n+1];
	for(int i=1;i<=n;i++) cin >> a[i];

	double lo = 0, hi=100, mid;
	double ans = 0;
	while(hi-lo>=err){
		mid = (lo+hi)/2;
		vector<double> pref;
		double sum = 0;
		pref.push_back(0);

		bool flag = false;
		for(int i=1;i<=n;i++){
			sum += (a[i]-mid);
			if(i>=d){
				if(sum-pref[i-d]>=0) flag = true;
			}

			pref.push_back(min(sum,pref.back()));
		}

		if(flag){
			ans = mid;
			lo = mid+err;
		}
		else hi = mid-err;
	}

	vector<double> pref;
	double sum = 0;
	pref.push_back(0);

	for(int i=1;i<=n;i++){
		sum += (a[i]-ans);
		if(i>=d && sum-pref[i-d]>=0){
			int j=0;
			for(j=0;j<i-d;j++) if(pref[j]<=sum) break;
			cout << j+1 << " "<<i<<endl;
			break;
		}

		pref.push_back(min(sum,pref.back()));
	}

}