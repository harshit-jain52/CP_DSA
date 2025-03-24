#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 5e5+5;

struct node{
	int sum;
	node(){sum=0;}
};

node seg[4*N];

node merge(node a, node b){
	node tmp;
	tmp.sum=a.sum+b.sum;
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].sum=1;
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void index(int id, int l, int r, int val, int& pos){
	if(l>r) return;
	if(l==r){
		pos=l;
		seg[id].sum=0;
		return;
	}

	int mid = (l+r)/2;
	if(seg[id<<1].sum>=val) index(id<<1,l,mid,val,pos);
	else index(id<<1|1,mid+1,r,val-seg[id<<1].sum,pos);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

int main()
{
	FASTIO
	int n; cin >> n;
	vector<int>p(n),ans(n);
	for(int i=0;i<n;i++) cin >> p[i];

	build(1,0,n-1);

	for(int i=n-1;i>=0;i--){
		int x=-1;
		index(1,0,n-1,p[i],x);
		ans[x]=i+1;
	}

	for(int i=0;i<n;i++) cout << ans[i] << " ";
}