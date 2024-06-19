#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	int sz, ct[32], lazy;
	node(){
		sz=lazy=0;
		for(int i=0;i<=31;i++) ct[i]=0;
	}
};

vector<int>g[N];
int in[N], out[N], arr[N];
node seg[4*N];

node merge(node a, node b){
	node tmp;
	tmp.sz = a.sz + b.sz;
	for(int i=0;i<=31;i++) tmp.ct[i] = a.ct[i] + b.ct[i];
	return tmp;
}

node init(int num){
	node tmp;
	tmp.sz = 1;
	for(int i=0;i<=31;i++) if((num>>i)&1) tmp.ct[i]=1;
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id]=init(arr[l]);
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

void push(int id, int l, int r){
	if(seg[id].lazy){
		int lz = seg[id].lazy;
		for(int i=0;i<=31;i++) if((lz>>i)&1) seg[id].ct[i] = seg[id].sz - seg[id].ct[i];

		if(l!=r){
			seg[id<<1].lazy ^= lz;
			seg[id<<1|1].lazy ^= lz;
		}

		seg[id].lazy=0;
	}
}

void update(int id, int l, int r, int lq, int rq, int val){
	push(id,l,r);
	if(l>rq || lq>r) return;
	if(l>=lq && r<=rq){
		seg[id].lazy = val;
		push(id,l,r);
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,lq,rq,val);
	update(id<<1|1,mid+1,r,lq,rq,val);
	seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq){
	push(id,l,r);
	if(l>rq || lq>r) return node();
	if(l>=lq && r<=rq) return seg[id];

	int mid = (l+r)/2;
	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int timer;
void dfs(int v, int pp){
	in[v]=timer++;
	for(int ch: g[v]) if(ch!=pp) dfs(ch,v);
	out[v]=timer;
}

int main()
{
	FASTIO
	int n,q; cin >> n >> q;
	for(int i=0;i<n-1;i++){
		int a,b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	timer=0;
	dfs(1,0);

	for(int i=1;i<=n;i++){
		int ai; cin >> ai;
		arr[in[i]]=ai;
	}

	build(1,0,n-1);

	while(q--){
		int ty,x; cin >>ty >> x;

		if(ty==1){
			int val; cin >> val;
			update(1,0,n-1,in[x],out[x]-1,val);
		}
		else{
			node tmp = query(1,0,n-1,in[x],out[x]-1);
			int ans = 0;
			if(tmp.sz>=2){
				if(ty==2){ for(int i=0;i<=31;i++) if(tmp.ct[i]>=tmp.sz-1) ans += (1<<i);}
				else {for(int i=0;i<=31;i++) if(tmp.ct[i]>=2) ans += (1<<i);}
			}
			cout << ans << endl;
		}
	}
}