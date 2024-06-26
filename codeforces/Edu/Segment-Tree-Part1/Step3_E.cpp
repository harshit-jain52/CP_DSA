#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	ll sum;
	node(){sum=0;}
};

node seg[4*N];

node merge(node a , node b){
	node tmp;
	tmp.sum = a.sum + b.sum;
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].sum=0;
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id] = merge(seg[id<<1], seg[id<<1|1]);
}

void update(int id, int l, int r, int pos, int v){
	if(l>r || l>pos || pos>r) return;
	if(l==r){
		seg[id].sum+=v;
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,pos,v);
	update(id<<1|1,mid+1,r,pos,v);
	seg[id] = merge(seg[id<<1], seg[id<<1|1]);
}

node query(int id, int l, int r, int rq){
	if(l>r || l>rq) return node();
	if(r<=rq) return seg[id];

	int mid = (l+r)/2;

	return merge(query(id<<1,l,mid,rq),query(id<<1|1,mid+1,r,rq));
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;

	build(1,0,n);
	while(m--){
		int tp; cin >> tp;
		if(tp==1){
			int l,r,v; cin >> l >> r >> v;
			update(1,0,n,l,v);
			update(1,0,n,r,-v);
		}
		else{
			int i; cin >> i;
			cout << query(1,0,n,i).sum<<endl;
		}
	}
}