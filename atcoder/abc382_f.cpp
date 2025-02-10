#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int W = 2e5+5;

struct node{
	int mx, lz;
	node(){
		mx=-1;
		lz=0;
	}
};

node seg[4*W];

node merge(node a, node b){
	node tmp;
	tmp.mx = max(a.mx,b.mx);
	return tmp;
}

void push(int id, int l, int r){
	if(seg[id].lz){
		seg[id].mx = seg[id].lz;
		if(l!=r){
			seg[id<<1].lz = seg[id].lz;
			seg[id<<1|1].lz = seg[id].lz;	
		}
		seg[id].lz=0;
	}
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].mx=0;
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void update(int id, int l, int r, int lq, int rq, int val){
	push(id,l,r);
	if(l>rq || lq>r) return;
	if(l>=lq && r<=rq){
		seg[id].lz=val;
		push(id,l,r);
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,lq,rq,val);
	update(id<<1|1,mid+1,r,lq,rq,val);
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
	int h,w,n; cin >> h >> w >> n;
	vector<vector<tuple<int,int,int>>>bar(h);
	vector<int>ans(n);

	for(int i=0;i<n;i++){
		int r,c,l; cin >> r >> c >> l;
		r--; c--;
		bar[r].push_back({c,l,i});
	}

	build(1,0,w-1);

	for(int r=h-1;r>=0;r--){
		for(auto b: bar[r]){
			auto [c,l,i] = b;
			node tmp = query(1,0,w-1,c,c+l-1);
			ans[i]=h-tmp.mx;
			update(1,0,w-1,c,c+l-1,tmp.mx+1);
		}
	}

	for(int i=0;i<n;i++) cout << ans[i] << endl;
}