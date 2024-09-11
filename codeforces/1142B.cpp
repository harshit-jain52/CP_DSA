#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int LOG = 21;


int main()
{
	FASTIO
	int n,m,q; cin >> n >> m >> q;
	int p[n], a[m], pos[n+1];
	for(int i=0;i<n;i++){cin >> p[i]; pos[p[i]]=i;}
	for(int i=0;i<m;i++) cin >> a[i];

	int nxt[m][LOG];
	
	vector<int>last(n+1,m);
	for(int i=m-1;i>=0;i--){
		nxt[i][0] = last[p[(pos[a[i]]+1)%n]];
		last[a[i]] = i;
		// cout << nxt[i][0] << " ";
	}

	for(int j=1;j<LOG;j++){
		for(int i=0;i<m;i++){
			int tmp = nxt[i][j-1];
			nxt[i][j] = ((tmp<m)?nxt[tmp][j-1]:m);
		}
	}

	vector<int>need(m), suff(m+1);
	suff[m]=m;
	for(int i=m-1;i>=0;i--){
		int u = i, k = n-1;

		for(int j=LOG-1;j>=0 && u<m;j--){
			if((k>>j)&1) u = nxt[u][j];
		}

		suff[i] = min(u,suff[i+1]);
	}

	while(q--){
		int l,r; cin >> l >> r;
		l--; r--;

		if(r-l+1<n || suff[l]>r) cout << '0';
		else cout << '1';
	}
}