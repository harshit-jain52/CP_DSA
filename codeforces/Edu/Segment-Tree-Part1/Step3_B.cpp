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
		seg[id].sum=1;
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
		seg[id].sum=0;
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,pos);
	update(id<<1|1,mid+1,r,pos);
	seg[id] = merge(seg[id<<1], seg[id<<1|1]);
}

void query(int id, int l, int r, int k, int &num){
	if(l>r) return;
	if(l==r){
		num = l;
		return;
	}
	int mid = (l+r)/2;
	if(seg[id<<1|1].sum>k) query(id<<1|1,mid+1,r,k,num);
	else query(id<<1,l,mid,k-seg[id<<1|1].sum,num);
}

int main()
{
	FASTIO
	int n; cin >> n;
	build(1,0,n-1);

	int inv[n];
	for(int i=0;i<n;i++) cin >> inv[i];
	
	stack<int>st;
	vector<int>p(n);
	for(int i=n-1;i>=0;i--){
		int num = -1;
		query(1,0,n-1,inv[i],num);
		update(1,0,n-1,num);
		p[i]=(num+1);
	}

	for(int i=0;i<n;i++) cout << p[i] << " ";
}