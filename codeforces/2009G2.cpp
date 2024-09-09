#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const int LOG = 20;
struct node{
	ll sumdp;
	int nxt;

	node(){
		sumdp = 0;
		nxt = 0;
	}
};

void solve(){
	int n,k,q; cin >> n >> k >> q;
	int a[n]; set<pii>st;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int j=-n; j<=n;j++) st.insert({0,j});

	ll f[n-k+1];
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


	stack<int>sta;
	vector<int>nle(n-k+1,n);
	for(int i=n-k;i>=0;i--){
		while(!sta.empty() && f[sta.top()]>f[i]) sta.pop();
		if(!sta.empty()) nle[i] = sta.top();
		sta.push(i);
	}

	// for(int i=0;i<=n-k;i++) cout << f[i] << " ";
	// cout << endl;
	// for(int i=0;i<=n-k;i++) cout << nle[i] << " ";
	// cout << endl;
	
	vector<vector<node>>lift(n-k+1,vector<node>(LOG,node()));

	for(int i=0;i<=n-k;i++){
		lift[i][0].nxt = nle[i];
		lift[i][0].sumdp = (nle[i]-i)*f[i];
	}
	for(int j=1;j<LOG;j++){
		for(int i=0;i<=n-k;i++){	
			int tmp = lift[i][j-1].nxt;
			lift[i][j].nxt = ((tmp<=n-k)?lift[tmp][j-1].nxt:n);
			lift[i][j].sumdp = lift[i][j-1].sumdp + ((tmp<=n-k)?lift[tmp][j-1].sumdp:0);	
		}
	}

	// for(int i=0;i<=n-k;i++){
	// 	for(int j=0;j<5;j++){
	// 		cout << lift[i][j].nxt << " ";
	// 	}
	// 	cout << endl;
	// }

	while(q--){
		int l,r; cin >> l >> r;
		l--; r--;
		ll ans = 0;
		for(int j=LOG-1;j>=0;j--){
			if(lift[l][j].nxt<=r-k+1){
				ans += lift[l][j].sumdp;
				// cout << ans << " ";
				l = lift[l][j].nxt;
			}
		}

		if(l<=n-k) ans += (r-k+1-l+1)*f[l];
		cout << ans << endl;
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