#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;
const int N = 2e5+5;

int subs[N];
string s;

struct node{
	int ans, st0, en0, st1, en1, len;
	node(){ans=st0=st1=en0=en1=0;}
};

node seg[4*N];

node init(int bit){
	node tmp;
	tmp.ans=tmp.len=1;
	tmp.st1=tmp.en1=bit;
	tmp.st0=tmp.en0=1^bit;
	return tmp;
}

node merge(node a, node b){
	node tmp;
	tmp.st0 = ((a.st0*1LL*subs[b.len])%M + b.st0)%M;
	tmp.st1 = ((a.st1*1LL*subs[b.len])%M + b.st1)%M;
	tmp.en0 = ((b.en0*1LL*subs[a.len])%M + a.en0)%M;
	tmp.en1 = ((b.en1*1LL*subs[a.len])%M + a.en1)%M;
	tmp.len = a.len+b.len;
	tmp.ans = ((a.ans*1LL*subs[b.len])%M + (b.ans*1LL*subs[a.len])%M)%M;
	tmp.ans = (tmp.ans - (a.en0*1LL*b.st0)%M + M)%M;
	tmp.ans = (tmp.ans - (a.en1*1LL*b.st1)%M + M)%M;
	return tmp;
}

void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id]=init(s[l]=='1');
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

void query(int id, int l, int r, int v){
	if(l>r || l>v || v>r) return;
	if(l==r){
		s[l] = '0'+'1'-s[l];
		seg[id]=init(s[l]=='1');
		return;
	}

	int mid = (l+r)/2;
	query(id<<1,l,mid,v);
	query(id<<1|1,mid+1,r,v);
	seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

void solve(){
	cin >> s;
	int n = s.size();

	build(1,0,n-1);
	// cout << seg[1].ans << endl;
	int q; cin >> q;
	while(q--){
		int v; cin >> v;
		query(1,0,n-1,v-1);
		cout << seg[1].ans << " ";
	}
	cout << endl;
}

int main()
{
	FASTIO
	subs[0]=1;
	for(int i=1;i<N;i++) subs[i] = (subs[i-1]*2LL)%M;
	// for(int i=1;i<N;i++) cout << subs[i] << " ";

	int t; cin >> t;
	while(t--) solve();
}