#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	int a[n], b[n];

	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];

	int m; cin >> m;
	int d[m];
	multiset<int>st;
	for(int i=0;i<m;i++){
		cin >> d[i];
		st.insert(d[i]);
	}

	bool flag = false;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			auto it = st.find(b[i]);
			if(it==st.end()){
				cout << "NO\n";
				return;
			}
			else st.erase(it);
		}
		if(b[i]==d[m-1]) flag = true;
	}

	if(flag) cout << "YES\n";
	else cout << "NO\n";
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