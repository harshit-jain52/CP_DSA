#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;
int mod;

struct node{
	ll a00, a01, a10, a11;
	node(){a00=a11=1; a01=a10=0;}
};

node arr[N];
node seg[4*N];

node merge(node a , node b){
	node tmp;
	tmp.a00 = ((a.a00*b.a00)%mod + (a.a01*b.a10)%mod)%mod;
	tmp.a01 = ((a.a00*b.a01)%mod + (a.a01*b.a11)%mod)%mod;
	tmp.a10 = ((a.a10*b.a00)%mod + (a.a11*b.a10)%mod)%mod;
	tmp.a11 = ((a.a10*b.a01)%mod + (a.a11*b.a11)%mod)%mod;
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id]=arr[l];
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
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
	int n,m; cin >> mod >> n >> m;

	for(int i=0;i<n;i++){
		cin >> arr[i].a00 >> arr[i].a01 >> arr[i].a10 >> arr[i].a11;
		arr[i].a00%=mod;
		arr[i].a01%=mod;
		arr[i].a10%=mod;
		arr[i].a11%=mod;
	}

	build(1,0,n-1);

	while(m--){
		int i,j; cin >> i >> j;
		node prod = query(1,0,n-1,i-1,j-1);
		cout << prod.a00 << " "<<prod.a01<<endl;
		cout << prod.a10 << " "<<prod.a11<<endl;
		cout << endl;
	}
}