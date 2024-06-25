#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool solve(){
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;

	if(x1<y1 && x2>y2) return true;
	if(x1>y1 && x2<y2) return true;
	return false;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		if(solve()) cout << "NO\n";
		else cout << "YES\n";
	}
}