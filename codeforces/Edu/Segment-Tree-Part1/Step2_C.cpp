#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	int mx;
	node(){mx=-1;}
};

int arr[N];
node seg[4*N];

node merge(node a , node b){
	node tmp;
	tmp.mx = max(a.mx,b.mx);
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].mx=arr[l];
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
		seg[id].mx=v;
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,pos,v);
	update(id<<1|1,mid+1,r,pos,v);
	seg[id] = merge(seg[id<<1], seg[id<<1|1]);
}

void query(int id, int l, int r, int x, int &pos){
	if(l>r || seg[id].mx<x) return;
	if(l==r){
		pos=l;
		return;
	}

	int mid = (l+r)/2;
	if(seg[id<<1].mx>=x) query(id<<1,l,mid,x,pos);
	else query(id<<1|1,mid+1,r,x,pos);
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	for(int i=0;i<n;i++) cin >> arr[i];

	build(1,0,n-1);
	while(m--){
		int tp; cin >> tp;
		if(tp==1){
			int i,v; cin >> i >> v;
			update(1,0,n-1,i,v);
		}
		else{
			int x, pos=-1; cin >> x;
			query(1,0,n-1,x,pos);
			cout << pos << endl;
		}
	}
}