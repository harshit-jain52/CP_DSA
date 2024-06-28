#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	ll pref, suff, sub, sum;
	ll lz;
	node(){pref=suff=sub=sum=0; lz=M;}
};
 
node seg[4*N];
 
node merge(node a , node b){
	node tmp;
	tmp.sum = a.sum+b.sum;
	tmp.pref = max({0LL,a.pref,a.sum+b.pref});
	tmp.suff = max({0LL,b.suff,a.suff+b.sum});
	tmp.sub = max({0ll,a.sub,b.sub,a.suff+b.pref});
	return tmp;
}

void push(int id, int l, int r){
	if(seg[id].lz!=M){
		seg[id].pref = seg[id].suff=seg[id].sub = max(0LL,(r-l+1)*seg[id].lz);
		seg[id].sum = (r-l+1)*seg[id].lz;
		if(l!=r){
			seg[id<<1].lz = seg[id].lz;
			seg[id<<1|1].lz = seg[id].lz;
		}
		seg[id].lz=M;
	}
}

void update(int id, int l, int r, int lq, int rq, int v){
	push(id,l,r);
	if(l>rq || lq>r) return;
	if(l>=lq && r<=rq){
		seg[id].lz = v;
		push(id,l,r);
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,lq,rq,v);
	update(id<<1|1,mid+1,r,lq,rq,v);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	
	while(m--){
		int l,r,v; cin >> l >> r >> v;
		update(1,0,n-1,l,r-1,v);
		cout << seg[1].sub << endl;
	}

}