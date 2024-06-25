#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int x,k,y;
	cin >> x >> y >> k;

	while(x>1){
		int req = y - x%y;
		if(k>=req){
			k-=req;
			x+=req;
			while(x%y==0) x/=y;
		}
		else break;
	}

	if(x==1){
		int req = y-1;
		k = k%req;
	}
	x+=k;

	cout << x << endl;
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