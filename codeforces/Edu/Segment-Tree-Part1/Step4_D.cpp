#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	vector<int>ct;
	node(){
		ct.assign(41,0);
	}
};

int arr[N];
node seg[4*N];

node merge(node a , node b){
	node tmp;
	for(int i=1;i<=40;i++) tmp.ct[i] = a.ct[i] + b.ct[i];
	
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].ct[arr[l]]=1;
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
		seg[id].ct[arr[l]]=0;
		arr[l]=v;
		seg[id].ct[arr[l]]=1;
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
	int n,q; cin >> n >> q;
	for(int i=0;i<n;i++) cin >> arr[i];

	build(1,0,n-1);
	while(q--){
		int tp,x,y; cin >> tp >> x >> y;
		if(tp==1){
			node tmp = query(1,0,n-1,x-1,y-1);
			int ans = 0;
			for(int i=1;i<=40;i++) ans += (tmp.ct[i]>0);
			cout << ans << endl;
		}
		else update(1,0,n-1,x-1,y);
	}
}