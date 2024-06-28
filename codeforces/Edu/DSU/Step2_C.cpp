#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

int r[N], par[N], sz[N];

int Find(int v){
	return ((par[v]==v)?v:par[v]=Find(par[v]));
}

int Right(int v){
	return ((r[v]==v)?v:r[v]=Right(r[v]));
}

inline void make(int v){
	par[v]=r[v]=v;
	sz[v]=1;
}

void Union(int u, int v){
	u = Find(u), v = Find(v);
	if(u==v) return;

	if(sz[u]<sz[v]) swap(u,v);
	sz[u] += sz[v];
	par[v]=u;
}

int main()
{
	FASTIO
	int n,q; cin >> n >> q;
	for(int i=1;i<=n;i++) make(i);

	while(q--){
		int tp,x,y; cin >> tp >> x >> y;
		if(tp==1){
			Union(x,y);
			int px = Find(x), py = Find(y);
			if(x>1 && Find(x-1)==px) r[x-1]=Right(x); 
			if(x<n && Find(x+1)==px) r[x]=Right(x+1); 
			if(y>1 && Find(y-1)==py) r[y-1]=Right(y);
			if(y<n && Find(y+1)==px) r[y]=Right(y+1); 
		}
		else if(tp==2){
			int lo=Right(x);
			int ry = Right(y);
			for(int i=lo;i<y;i=Right(i+1)){
				Union(i,i+1);
				r[i]=ry;
			}

			int px = Find(x), py = Find(y);
			if(x>1 && Find(x-1)==px) r[x-1]=Right(x); 
			if(x<n && Find(x+1)==px) r[x]=Right(x+1);
			if(y>1 && Find(y-1)==py) r[y-1]=Right(y);
			if(y<n && Find(y+1)==px) r[y]=Right(y+1); 
		}
		else{
			if(Find(x)==Find(y)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}