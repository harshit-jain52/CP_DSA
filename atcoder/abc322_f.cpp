#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 5e5+5;

struct node{
    int pref0, suff0, sub0, ct0;
    int pref1, suff1, sub1, ct1;
    int len,lz;
    node(){
        pref0=pref1=suff0=suff1=sub0=sub1=ct0=ct1=len=lz=0;
    }
};
 
string s;
node seg[4*N];
 
node merge(node a, node b){
    node tmp;
    tmp.pref0 = a.pref0 + (int)(a.ct0 == a.len)*(b.pref0);
    tmp.pref1 = a.pref1 + (int)(a.ct1 == a.len)*(b.pref1);
    tmp.suff0 = b.suff0 + (int)(b.ct0 == b.len)*(a.suff0);
    tmp.suff1 = b.suff1 + (int)(b.ct1 == b.len)*(a.suff1);
    tmp.ct0 = a.ct0 + b.ct0;
    tmp.ct1 = a.ct1 + b.ct1;
    tmp.len = a.len + b.len;
    tmp.sub0 = max({a.sub0,b.sub0,a.suff0+b.pref0});
    tmp.sub1 = max({a.sub1,b.sub1,a.suff1+b.pref1});
    return tmp;
}

void push(int id, int l, int r){
	if(seg[id].lz){
		swap(seg[id].pref0,seg[id].pref1);
		swap(seg[id].suff0,seg[id].suff1);
		swap(seg[id].sub0,seg[id].sub1);
		swap(seg[id].ct0,seg[id].ct1);

		if(l!=r){
			seg[id<<1].lz ^= 1;
			seg[id<<1|1].lz ^= 1;
		}

		seg[id].lz=0;
	}
}

void build(int id, int l, int r){
    if(l>r) return;
    if(l==r){
        if(s[l]=='0') seg[id].pref0=seg[id].suff0=seg[id].ct0=seg[id].sub0=1; 
        else seg[id].pref1=seg[id].suff1=seg[id].ct1=seg[id].sub1=1;
        seg[id].len=1;
        return; 
    }
 
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void update(int id, int l, int r, int lq, int rq){
	push(id,l,r);
	if(l>rq || lq>r) return;
	if(l>=lq && r<=rq){
		seg[id].lz=1;
		push(id,l,r);
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,lq,rq);
	update(id<<1|1,mid+1,r,lq,rq);
    seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq){
	push(id,l,r);
	if(l>rq || lq>r) return node();
	if(l>=lq && r<=rq) return seg[id];

	int mid = (l+r)/2;
	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
	FASTIO
	int n,q; cin >> n >> q;
	cin >> s;
	build(1,0,n-1);

	while(q--){
		int c,l,r; cin >> c >> l >> r;
		if(c==1) update(1,0,n-1,l-1,r-1);
		else cout << query(1,0,n-1,l-1,r-1).sub1 << endl;
	}
}