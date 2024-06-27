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
	while(n--){
		int x, y; cin >> x >> y;
		if(y>=-1) cout << "YES\n";
		else cout << "NO\n";
	}
}