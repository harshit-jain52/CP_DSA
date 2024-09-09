#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;

void solve(){
	int n,k,q; cin >> n >> k >> q;
	int a[n]; set<pii>st;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int j=-n; j<=n;j++) st.insert({0,j});

	int f[n-k+1];
	map<int,int>ct;
	
	for(int r=0;r<n;r++){
		int tmp = a[r]-r-1;
		st.erase({ct[tmp],tmp});
		ct[tmp]++;
		st.insert({ct[tmp],tmp});

		int l=r-k+1;
		if(l>=0){
			if(l>0){
				tmp = a[l-1]-(l-1)-1;
				st.erase({ct[tmp],tmp});
				ct[tmp]--;
				st.insert({ct[tmp],tmp});
			}
			f[l] = k-(st.rbegin()->first);		
		}
	}

	while(q--){
		int l,r; cin >> l >> r; // r=l+k-1
		cout << f[l-1] << endl;
	}
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