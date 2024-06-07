#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	int lazy;
	int ct[20];
	node(){
		lazy=0;
		for(int i=0;i<20;i++) ct[i]=0;
	}
};

int a[N];
node seg[4*N];

node merge(node a, node b){
	node tmp;
	for(int i=0;i<20;i++) tmp.ct[i]=a.ct[i]+b.ct[i];
	return tmp;
}

void push(int id, int l, int r){
	if(seg[id].lazy){
		int len = r-l+1;
		for(int i=0;i<20;i++){
			if((seg[id].lazy>>i)&1) seg[id].ct[i] = len-seg[id].ct[i];
		}
		if(l!=r){
			seg[id<<1].lazy^=seg[id].lazy;
			seg[id<<1|1].lazy^=seg[id].lazy;
		}
		seg[id].lazy=0;
	}
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		for(int i=0;i<20;i++){
			if((1<<i)&a[l]) seg[id].ct[i]=1;
		}
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

void update(int id, int l, int r, int lq, int rq, int x){
	push(id,l,r);
	if(lq>r || l>rq) return;
	if(l>=lq && r<=rq){
		seg[id].lazy=x;
		push(id,l,r);
		return;
	}

	int mid=(l+r)/2;
	update(id<<1,l,mid,lq,rq,x);
	update(id<<1|1,mid+1,r,lq,rq,x);
	seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq){
	push(id,l,r);
	if(lq>r || l>rq) return node();
	if(l>=lq && r<=rq) return seg[id];

	int mid=(l+r)/2;
	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];

	build(1,0,n-1);

	int m; cin >> m;
	while(m--){
		int t,l,r;
		cin >> t >> l >> r;

		if(t==1){
			node tmp = query(1,0,n-1,l-1,r-1);
			ll sum = 0;
			for(int i=0;i<20;i++){
				sum += (1LL<<i)*tmp.ct[i];
			}
			cout << sum << endl;
		}
		else{
			int x; cin >> x;
			update(1,0,n-1,l-1,r-1,x);
		}
	}
}