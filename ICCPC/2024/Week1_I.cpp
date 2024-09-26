#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

struct node{
	int lf,rt,maxdiff;
	node(){lf=rt=maxdiff=0;}
};

int a[N];
node seg[4*N];

node merge(node a, node b){
	node tmp;
	tmp.lf = a.lf;
	tmp.rt = b.rt;
	tmp.maxdiff = max({a.maxdiff,b.maxdiff,abs(a.rt-b.lf)});
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].lf = seg[id].rt = a[l];
		seg[id].maxdiff = 0;
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void update(int id, int l, int r, int pos, int val){
	if(l>r || l>pos || pos>r) return;

	if(l==r){
		seg[id].lf = seg[id].rt = val;
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void query(int id, int l, int r, int start, int lim, int &ans){
	if(l>r || start>r) return;
	if(seg[id].maxdiff <= lim){
		ans = r;
		// cout << "ID:"<<id <<" "<<seg[id].maxdiff << " "<<ans<<endl;
		return;
	}

	int mid = (l+r)/2;
	query(id<<1,l,mid,start,lim,ans);
	if(ans>mid || (ans==mid && abs(seg[id<<1].rt-seg[id<<1|1].lf)<=lim)) query(id<<1|1,mid+1,r,start,lim,ans);
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];

	build(1,0,n-1);
	// cout << seg[1].maxdiff << endl;
	int q; cin >> q;
	while(q--){
		int x,y,z; cin >> x >> y >> z;
		if(x==1) update(1,0,n-1,y-1,z);
		else{
			int ans = y-1;
			query(1,0,n-1,y-1,z,ans);
			cout << ans+1 << endl;
		}
	}
}