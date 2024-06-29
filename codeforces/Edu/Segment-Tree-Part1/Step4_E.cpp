#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	int mn,idx;
	node(){mn=INT_MAX, idx=-1;}
};

node seg[4*N];

node merge(node a , node b){
	if(a.mn<b.mn) return a;
	else return b;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].mn=INT_MAX;
		seg[id].idx = l;
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
		seg[id].mn = v;
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
	int n,m; cin >> n >> m;
	
	build(1,0,n-1);
	
	while(m--){
		int tp; cin >> tp;
		if(tp==2){
			int l,r,p,ct=0; cin >> l >> r >> p;
			while(1){
				node tmp = query(1,0,n-1,l,r-1);
				if(tmp.mn>p) break;
				ct++;
				update(1,0,n-1,tmp.idx,INT_MAX);
			}
			cout << ct << endl;
		}
		else{
			int i,h; cin >> i >> h;
			update(1,0,n-1,i,h);
		}
	}
}