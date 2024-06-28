#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	int sum;
	int lz;
	node(){sum=0;lz=0;}
};
 
node seg[4*N];
 
node merge(node a , node b){
	node tmp;
	tmp.sum = a.sum + b.sum;
	return tmp;
}

void push(int id, int l, int r){
	if(seg[id].lz){
		seg[id].sum = (r-l+1) - seg[id].sum;
		if(l!=r){
			seg[id<<1].lz^=1;
			seg[id<<1|1].lz^=1;
		}
		seg[id].lz=0;
	}
}

void update(int id, int l, int r, int lq, int rq){
	push(id,l,r);
	if(l>rq || lq>r) return;
	if(l>=lq && r<=rq){
		seg[id].lz = 1;
		push(id,l,r);
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,lq,rq);
	update(id<<1|1,mid+1,r,lq,rq);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void query(int id, int l, int r, int k, int &pos){
	push(id,l,r);
	if(l!=r){
		int mid = (l+r)/2;
		push(id<<1,l,mid);
		push(id<<1|1,mid+1,r);
	}

	if(l==r){
		pos=l;
		return;
	}
 
	int mid = (l+r)/2;
	if(seg[id<<1].sum>=k) query(id<<1,l,mid,k,pos);
	else query(id<<1|1,mid+1,r,k-seg[id<<1].sum,pos);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	
	while(m--){
		int tp; cin >> tp;
		if(tp==1){
			int l,r; cin >> l >> r;
			update(1,0,n-1,l,r-1);
		}
		else{
			int k,pos; cin >> k;
			query(1,0,n-1,k+1,pos);
			cout << pos << endl;
		}
	}

}