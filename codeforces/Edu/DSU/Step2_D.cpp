#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e9+7;
const int N = 3e5+5;
#define F first
#define S second

pii par[N];

void make(int v){
	par[v] = {v,0};
}

pii Find(int v){
	if(par[v].F != v){
		int d = par[v].S;
		par[v] = Find(par[v].F);
		par[v].S += d;
	}
	return par[v];
}

void Union(int u, int v){
	pii b = Find(v);
	par[u] = {b.F,1+b.S};
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++) make(i);

	while(m--){
		int tp; cin >> tp;
		if(tp==1){
			int a,b; cin >> a >> b;
			Union(a,b);
		}
		else{
			int c; cin >> c;
			cout << Find(c).S << endl;
		}
	}	
}