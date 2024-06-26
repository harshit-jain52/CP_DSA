#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	int sum;
	node(){sum=0;}
};

int arr[N];
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

void update(int id, int l, int r, int pos){
	if(l>r || l>pos || pos>r) return;
	if(l==r){
		seg[id].sum++;
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,pos);
	update(id<<1|1,mid+1,r,pos);
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
	build(1,0,N-1);
	
	int n; cin >> n;

	for(int i=0;i<n;i++){
		int p; cin >> p;
		cout << query(1,0,N-1,p+1,N-1).sum << " ";
		update(1,0,N-1,p);
	}
}