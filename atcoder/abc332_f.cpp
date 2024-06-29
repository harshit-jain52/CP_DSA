#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;
const int N = 2e5+5;
struct node{
	int val, mul, add;
	node(){val=0;mul=1;add=0;}
};

int binpow(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = (ans*1LL*a)%M;
		a = (a*1LL*a)%M;
		b>>=1;
	}
	return ans;
}

int arr[N], inv[N];
node seg[4*N];

void push(int id, int l, int r){
	if(seg[id].mul!=1 || seg[id].add !=0){
		if(l==r){
			seg[id].val = ((seg[id].val*1LL*seg[id].mul)%M + seg[id].add)%M;
		}
		else{
			seg[id<<1].mul = (seg[id<<1].mul*1LL*seg[id].mul)%M;
			seg[id<<1].add = ((seg[id<<1].add*1LL*seg[id].mul)%M + seg[id].add)%M;
			seg[id<<1|1].mul = (seg[id<<1|1].mul*1LL*seg[id].mul)%M;
			seg[id<<1|1].add = ((seg[id<<1|1].add*1LL*seg[id].mul)%M + seg[id].add)%M;
		}
		seg[id].mul=1;
		seg[id].add=0;
	}
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].val = arr[l]%M;
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void update(int id, int l, int r, int lq, int rq, int len, int x){
	push(id,l,r);
	if(l>rq || lq>r) return;
	if(l>=lq && r<=rq){
		seg[id].mul = ((len-1)*1LL*inv[len])%M;
		seg[id].add = (inv[len]*1LL*x)%M;
		push(id,l,r);
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,lq,rq,len,x);
	update(id<<1|1,mid+1,r,lq,rq,len,x);
}

int query(int id, int l, int r, int pos){
	push(id,l,r);
	if(l==r) return seg[id].val;

	int mid=(l+r)/2;
	if(pos<=mid) return query(id<<1,l,mid,pos);
	else return query(id<<1|1,mid+1,r,pos);
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;

	for(int i=1;i<=n;i++) inv[i]=binpow(i,M-2);
	for(int i=0;i<n;i++) cin >> arr[i];

	build(1,0,n-1);

	while(m--){
		int l,r,x; cin >> l >> r >> x;
		update(1,0,n-1,l-1,r-1,r-l+1,x%M);
	}

	for(int i=0;i<n;i++){
		cout << query(1,0,n-1,i) << " ";
	}
}