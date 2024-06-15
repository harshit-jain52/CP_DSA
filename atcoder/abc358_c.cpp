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
	int mask[n];
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		mask[i]=0;
		for(int j=0;j<m;j++){
			if(s[j]=='o') mask[i]+=(1LL<<j);
		}
	}

	int ans = n;
	for(int num=0;num<(1<<n);num++){
		int tmp = 0;
		for(int bit=0;bit<n;bit++){
			if((num>>bit)&1) tmp |= mask[bit];
		}

		if(__builtin_popcount(tmp)==m) ans = min(ans,__builtin_popcount(num));
	}

	cout << ans;
}