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
		int mid1 = lo + (hi-lo)/3;
		int mid2 = lo + 2*(hi-lo)/3;
		printf("? %d %d", mid1, mid2);
		cout << endl;
		int area; cin >> area;
		if(area == mid1*mid2) lo = mid2+1;
		else if(area == mid1*(mid2+1)){
			x = mid2;
			lo = mid1+1;
			hi = mid2-1;
		}
		else{
			x = mid1;
			hi = mid1-1;
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