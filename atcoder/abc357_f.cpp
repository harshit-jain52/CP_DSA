#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;
const int N = 2e5+5;

struct node{
	int asum,bsum,tot;
	int lz1,lz2;
	node(){asum=bsum=tot=lz1=lz2=0;}
};

int a[N], b[N];
node seg[4*N];

node merge(node x, node y){
	node tmp;
	tmp.asum = (x.asum+y.asum)%M;
	tmp.bsum = (x.bsum+y.bsum)%M;
	tmp.tot = (x.tot+y.tot)%M;
	return tmp;
}

void push(int id, int l, int r){
	if(seg[id].lz1 || seg[id].lz2){
		int len = r-l+1;
		seg[id].tot = (seg[id].tot + (seg[id].asum*1LL*seg[id].lz2)%M)%M;
		seg[id].tot = (seg[id].tot + (seg[id].bsum*1LL*seg[id].lz1)%M)%M;
		seg[id].tot = (seg[id].tot + (len*1LL*((seg[id].lz1*1LL*seg[id].lz2)%M))%M)%M;
		seg[id].asum = (seg[id].asum + (len*1LL*seg[id].lz1)%M)%M;
		seg[id].bsum = (seg[id].bsum + (len*1LL*seg[id].lz2)%M)%M;
		if(l!=r){
			seg[id<<1].lz1 = (seg[id<<1].lz1 + seg[id].lz1)%M;
			seg[id<<1].lz2 = (seg[id<<1].lz2 + seg[id].lz2)%M;
			seg[id<<1|1].lz1 = (seg[id<<1|1].lz1 + seg[id].lz1)%M;
			seg[id<<1|1].lz2 = (seg[id<<1|1].lz2 + seg[id].lz2)%M;
		}

		seg[id].lz1 = seg[id].lz2 = 0;
	}
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].asum = a[l];
		seg[id].bsum = b[l];
		seg[id].tot = (a[l]*1LL*b[l])%M;
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void update(int id, int l, int r, int lq, int rq, int tp, int x){
	push(id,l,r);
	if(l>rq || lq>r) return;
	
	if(l>=lq && r<=rq){
		if(tp==1) seg[id].lz1 = x;
		else seg[id].lz2 = x;
		push(id,l,r);
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,lq,rq,tp,x);
	update(id<<1|1,mid+1,r,lq,rq,tp,x);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq){
	push(id,l,r);
	if(l>rq || lq>r) return node();
	if(l>=lq && r<=rq) return seg[id];

	int mid=(l+r)/2;
	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
	FASTIO
	int n,q; cin >> n >> q;

	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];

	build(1,0,n-1);

	while(q--){
		int tp,l,r; cin >> tp >> l >> r;
		if(tp==3) cout << query(1,0,n-1,l-1,r-1).tot << endl;
		else{
			int x; cin >> x;
			update(1,0,n-1,l-1,r-1,tp,x);
		}
	}
}