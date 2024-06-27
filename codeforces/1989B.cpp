#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	string a,b;
	cin >> a >> b;

	int n = a.size(), m = b.size();
	
	int len = 0;
	for(int i=0;i<m;i++){
		int idx = i;
		for(int j=0;j<n && idx<m;j++){
			if(a[j]==b[idx]) idx++;
		}
		len = max(len,idx-i);
	}

	cout << n + m - len << endl;
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