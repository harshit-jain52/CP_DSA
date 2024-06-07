#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e6+5;

struct node{
	int left;
	int right;
	int sub;
	node(){left=right=sub=0;}
};

string s;
node seg[4*N];

node merge(node a, node b){
	node tmp;
	int x = min(a.left,b.right);
	tmp.sub = a.sub+b.sub+x;
	tmp.left = a.left+b.left-x;
	tmp.right = a.right+b.right-x;
	return tmp;
}


void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		if(s[l]=='(') seg[id].left=1;
		else seg[id].right=1;
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}



node query(int id, int l, int r, int lq, int rq){
	if(l>r || lq>r || l>rq) return node();
	if(l>=lq && r<=rq) return seg[id];

	int mid=(l+r)/2;
	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
	FASTIO
	cin >> s;
	int n = s.size();

	build(1,0,n-1);

	int m; cin >> m;
	while(m--){
		int l,r;
		cin >> l >> r;
		cout << 2*query(1,0,n-1,l-1,r-1).sub<<endl;
	}
}