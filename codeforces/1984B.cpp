#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool solve(){
	string x; cin >> x;
	int n = x.size();

	if(x[n-1]=='9') return false;
	if(x[0]!='1') return false;

	for(int i=0;i<=n-2;i++) if(x[i]=='0') return false;

	return true;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}