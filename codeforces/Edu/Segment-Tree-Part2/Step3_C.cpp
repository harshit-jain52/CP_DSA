#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	ll mx;
	int lz;
	node(){mx=0;lz=0;}
};
 
node seg[4*N];
 
node merge(node a , node b){
	node tmp;
	tmp.mx = max(a.mx,b.mx);
	return tmp;
}

void push(int id, int l, int r){
	if(seg[id].lz){
		seg[id].mx += seg[id].lz;
		if(l!=r){
			seg[id<<1].lz += seg[id].lz;
			seg[id<<1|1].lz += seg[id].lz;
		}
		seg[id].lz=0;
	}
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

void query(int id, int l, int r, int lq, int x, int &pos){
	push(id,l,r);
	if(lq>r || seg[id].mx<x || pos!=-1) return;
	if(l==r){
		pos=l;
		return;
	}
 
	int mid = (l+r)/2;
	query(id<<1,l,mid,lq,x,pos);
	query(id<<1|1,mid+1,r,lq,x,pos);
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	
	while(m--){
		int tp; cin >> tp;
		if(tp==1){
			int l,r,v; cin >> l >> r >> v;
			update(1,0,n-1,l,r-1,v);
		}
		else{
			int x,l,pos=-1; cin >> x >> l;
			query(1,0,n-1,l,x,pos);
			cout << pos << endl;
		}
	}
}