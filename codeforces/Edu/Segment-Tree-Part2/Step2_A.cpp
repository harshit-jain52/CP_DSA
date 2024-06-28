#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	ll mn,lz;
	node(){mn=1e16; lz=0;}
};

node seg[4*N];

node merge(node a, node b){
	node tmp;
	tmp.mn = min(a.mn, b.mn);
	return tmp;
}

void push(int id, int l, int r){
	if(seg[id].lz){
		seg[id].mn += seg[id].lz;
		if(l!=r){
			seg[id<<1].lz += seg[id].lz;
			seg[id<<1|1].lz += seg[id].lz;
		}
		seg[id].lz=0;
	}
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].mn=0;
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void update(int id, int l, int r, int lq, int rq, int v){
	push(id,l,r);
	if(l>rq || lq>r) return;
	if(l>=lq && r<=rq){
		seg[id].lz = v;
		push(id,l,r);
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,lq,rq,v);
	update(id<<1|1,mid+1,r,lq,rq,v);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq){
	push(id,l,r);
	if(l>rq || lq>r) return node();
	if(l>=lq && r<=rq) return seg[id];

	int mid = (l+r)/2;
	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	build(1,0,n-1);
	
	while(m--){
		int tp,l,r; cin >> tp >> l >> r;
		if(tp==1){
			int v; cin >> v;
			update(1,0,n-1,l,r-1,v);
		}
		else cout << query(1,0,n-1,l,r-1).mn << endl;
	}

}