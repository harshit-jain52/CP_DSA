#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool solve(){
	int n;
	cin >> n;
	ll a[n+1];

	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i%2==0) a[i] = -a[i];
	}

	set<ll>st;
	st.insert(0);
	ll sum = 0;

	for(int i=1;i<=n;i++){
		sum += a[i];

		if(st.find(sum)!=st.end()) return true;
		st.insert(sum);
	}

	return false;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		if(solve()) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}