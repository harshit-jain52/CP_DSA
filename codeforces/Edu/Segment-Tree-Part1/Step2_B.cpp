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
		seg[id].sum=arr[l];
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
		seg[id].sum= 1^seg[id].sum;
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,pos);
	update(id<<1|1,mid+1,r,pos);
	seg[id] = merge(seg[id<<1], seg[id<<1|1]);
}

void query(int id, int l, int r, int k, int &pos){
	if(l>r) return;
	if(l==r){
		pos=l;
		return;
	}

	int mid = (l+r)/2;
	if(seg[id<<1].sum>=k) query(id<<1,l,mid,k,pos);
	else query(id<<1|1,mid+1,r,k-seg[id<<1].sum,pos);
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
			int i; cin >> i;
			update(1,0,n-1,i);
		}
		else{
			int k, pos; cin >> k;
			query(1,0,n-1,k+1,pos);
			cout << pos << endl;
		}
	}
}