#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
	int gcd;
	int mn;
	int ct;
	node(){gcd=ct=0;mn=INT_MAX;}
};

int s[N];
node seg[4*N];

node merge(node a, node b){
	node tmp;
	tmp.gcd = __gcd(a.gcd,b.gcd);
	if(a.mn<b.mn){
		tmp.mn = a.mn;
		tmp.ct = a.ct;
	}
	else if(a.mn>b.mn){
		tmp.mn = b.mn;
		tmp.ct = b.ct;
	}
	else{
		tmp.mn = a.mn;
		tmp.ct = a.ct + b.ct;
	}

	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id].ct=1;
		seg[id].mn=seg[id].gcd=s[l];
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
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> s[i];

	build(1,0,n-1);

	int t; cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;

		node tmp = query(1,0,n-1,l-1,r-1);
		int len = r-l+1;

		if(tmp.mn == tmp.gcd) cout << (len - tmp.ct);
		else cout << len;
		cout << endl;
	}
}