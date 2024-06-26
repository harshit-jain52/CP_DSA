#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	ll f,s;
	node(){f=s=0;}
};

int arr[N];
node seg[4*N];

node merge(node a , node b){
	node tmp;
	tmp.f = a.f+b.f;
	tmp.s = a.s+b.s;	
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		if(l&1) seg[id].s = arr[l];
		else seg[id].f = arr[l];
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
		if(l&1) seg[id].s = v;
		else seg[id].f = v;
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,pos,v);
	update(id<<1|1,mid+1,r,pos,v);
	seg[id] = merge(seg[id<<1], seg[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq){
	if(l>r || l>rq || lq>r) return node();
	if(l>=lq && r<=rq) return seg[id];

	int mid = (l+r)/2;

	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	
	build(1,0,n-1);

	int m; cin >> m;
	
	while(m--){
		int tp; cin >> tp;
		if(tp){
			int l,r; cin >> l >> r;
			node tmp = query(1,0,n-1,l-1,r-1);
			ll ans = tmp.f - tmp.s;
			if((l-1)&1) ans = -ans;
			cout << ans << endl;
		}
		else{
			int i,j; cin >> i >> j;
			update(1,0,n-1,i-1,j);
		}
	}
}