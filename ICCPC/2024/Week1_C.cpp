#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int MOD = 1e9+7;
const int M = 1e5+5;
const int N = 250;
#define F first
#define S second

struct node{
	int par[N], sz[N], comp;
	node(){
		for(int i=0;i<N;i++){
			par[i]=i;
			sz[i]=1;
			comp=N;
		}
	}

	int Find(int u){
		return ((par[u]==u)?u:par[u]=Find(par[u]));
	}

	void Union(int u, int v){
		u = Find(u); v = Find(v);
		if(u==v) return;

		comp--;
		if(sz[u]<sz[v]) swap(u,v);
		sz[u]+=sz[v];
		par[v] = u;
	}
};

vector<pair<int,int>>br(M);
node seg[4*M];

node merge(node a, node b){
	if(a.comp>b.comp) swap(a,b);
	for(int i=0;i<N;i++){
		a.Union(i,b.Find(i));
	}
	return a;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].Union(br[l].F,br[l].S);
		return;
	}

	int mid = (l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void update(int id, int l, int r, int b, int u, int v){
	if(l>r || l>b || b>r) return;
	if(l==r){
		seg[id] = node();
		seg[id].Union(u,v);
		return;
	}

	int mid = (l+r)>>1;
	update(id<<1,l,mid,b,u,v);
	update(id<<1|1,mid+1,r,b,u,v);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq){
	if(l>r || l>rq || lq>r) return node();
	if(l>=lq && r<=rq) return seg[id];

	int mid = (l+r)>>1;
	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
	FASTIO
	int n,m,q; cin >> n >> m >> q;

	for(int i=0;i<m;i++) cin >> br[i].F >> br[i].S;

	int diff = N-n;
	build(1,0,m-1);
	node curr = seg[1];

	// for(int i=1;i<=9;i++){
	// 	for(int j=0;j<n;j++) cout << seg[i].Find(j)<<" ";
	// 	cout << endl;
	// }
	vector<int>last={0,-1,-1};

	while(q--){
		int tp; cin >> tp;
		if(tp==4){
			int u,v; cin >> u >> v;
			cout << ((curr.Find(u)==curr.Find(v))?"YES\n":"NO\n");
		}
		else{
			if(tp==3){
				int b,u,v; cin >> b >> u >> v;
				update(1,0,m-1,b,u,v);
				switch(last[0]){
				case 0:
					curr = seg[1];
					break;
				case 1:
					curr = query(1,0,m-1,last[1],last[2]);
					break;
				case 2:
					curr = merge(query(1,0,m-1,0,last[1]-1),query(1,0,m-1,last[2]+1,m-1));
					break;
				}
			}
			else if(tp==1){
				int l,r; cin >> l >> r;
				curr = query(1,0,m-1,l,r);
				last = {1,l,r};
			}
			else{
				int l,r; cin >> l >> r;
				curr = merge(query(1,0,m-1,0,l-1),query(1,0,m-1,r+1,m-1));
				last = {2,l,r};
			}

			// cout << "here:\n"<<endl;
			// for(int j=0;j<n;j++) cout << curr.Find(j)<<" ";
			// 	cout << endl;
			cout << curr.comp - diff << endl;
		}
	}
}