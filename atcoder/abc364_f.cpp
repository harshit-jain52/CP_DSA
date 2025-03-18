#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 4e5+5;

int nxt[N];

int Next(int v){
	return ((nxt[v]==v)?v:nxt[v]=Next(nxt[v]));
}

inline void make(int v){
	nxt[v]=v;
}

int main()
{
	FASTIO
	int n,q; cin >> n >> q;
	vector<array<ll,4>>qu(q);
	for(int i=0;i<q;i++) cin >> qu[i][1] >> qu[i][2] >> qu[i][0];
	for(int i=1;i<=n+1;i++) make(i);

	sort(qu.begin(),qu.end());
	ll cost=0;

	for(int i=0;i<q;i++){
		int l = qu[i][1], r = qu[i][2];
		ll c = qu[i][0];

		int j=Next(l);
		cost+=c;
		while(j<r){
			nxt[j]=j+1;
			cost += c;
			j=Next(j);
		}
	}

	cout << ((Next(1)<n)?-1:cost) << endl;	
}