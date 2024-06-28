#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e6+6;

int  par[N];

int Find(int v){
	return ((par[v]==v)?v:par[v]=Find(par[v]));
}

void Union(int u, int v){
	u = Find(u); v = Find(v);
	if(u==v) return;
	par[u]=v;
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;

	for(int i=1;i<=n+1;i++) par[i]=i;

	while(m--){
		char tp; int x;
		cin >> tp >> x;
		if(tp=='?'){
			int r = Find(x);
			cout << ((r<=n)?r:-1) << endl;
		}
		else par[x]=x+1;
	}
}