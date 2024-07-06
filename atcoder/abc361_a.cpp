#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,k,x;
	cin >> n >> k >> x;

	for(int i=0;i<n;i++){
		int a; cin >> a;
		cout << a << " ";
		if(i==k-1) cout << x << " ";
	}
}