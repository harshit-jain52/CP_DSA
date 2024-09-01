#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int lo = 2, hi = 999;
	int x = hi;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		printf("? %d %d", mid, mid);
		cout << endl;
		int area; cin >> area;
		if(area == mid*mid) lo = mid+1;
		else{
			x = mid;
			hi = mid-1;
		}
	}

	printf("! %d",x);
	cout << endl;
}

int main()
{
	// FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}