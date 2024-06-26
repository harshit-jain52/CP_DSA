#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	ll pref, suff, sub, sum;
	node(){pref=suff=sub=sum=0;}
};

ll arr[N];
node seg[4*N];

node merge(node a , node b){
	node tmp;
	tmp.sum = a.sum+b.sum;
	tmp.pref = max({0LL,a.pref,a.sum+b.pref});
	tmp.suff = max({0LL,b.suff,a.suff+b.sum});
	tmp.sub = max({0ll,a.sub,b.sub,a.suff+b.pref});
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].pref=seg[id].suff=seg[id].sub=max(arr[l],0LL);
		seg[id].sum = arr[l];
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id] = merge(seg[id<<1], seg[id<<1|1]);
}

void update(int id, int l, int r, int pos, ll v){
	if(l>r || l>pos || pos>r) return;
	if(l==r){
		seg[id].pref=seg[id].suff=seg[id].sub=max(v,0LL);
		seg[id].sum = v;
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,pos,v);
	update(id<<1|1,mid+1,r,pos,v);
	seg[id] = merge(seg[id<<1], seg[id<<1|1]);
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	for(int i=0;i<n;i++) cin >> arr[i];

	build(1,0,n-1);
	cout << seg[1].sub << endl;
	while(m--){
		int i,v; cin >> i >> v;
		update(1,0,n-1,i,v);
		cout << seg[1].sub << endl;
	}
}