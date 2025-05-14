#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const int N = 2e5+5;

struct Query {
    int a, b, val, idx, f;
    bool operator<(Query other) const{	
        return val < other.val;
    }
};

vector<int>seg(4*N,0);

void update(int id, int l, int r, int pos){
	if(l>r || pos>r || l>pos) return;
	if(l==r){
		seg[id]=1;
		return;
	}

	int mid = (l+r)/2;
	if(pos<=mid) update(id<<1,l,mid,pos);
	else update(id<<1|1,mid+1,r,pos);
	seg[id] = seg[id<<1]+seg[id<<1|1];
}

int query(int id, int l, int r, int lq, int rq){
	if(l>r || l>rq || lq>r) return 0;
	if(l>=lq && r<=rq) return seg[id];

	int mid = (l+r)/2;
	return (query(id<<1,l,mid,lq,rq)+query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
	FASTIO
	int n,q; cin >> n >> q;

	vector<pii>x(n);
	for(int i=0;i<n;i++){
		cin >> x[i].F;
		x[i].S = i;
	}
	sort(x.begin(),x.end());

	vector<Query>qu(2*q);
	for(int i=0;i<2*q;i+=2){
		int a,b,c,d; cin >> a >> b >> c >> d;
		a--; b--;
		qu[i].a = qu[i+1].a = a;
		qu[i].b = qu[i+1].b = b;
		qu[i].val = c-1;
		qu[i+1].val = d;
		qu[i].f = -1;
		qu[i+1].f = 1;
		qu[i].idx = qu[i+1].idx = i/2;
	}
	sort(qu.begin(),qu.end());

	vector<int>ans(q,0);
	int j=0;
	for(int i=0;i<2*q;i++){
		while(j<n && x[j].F<=qu[i].val){
			update(1,0,n-1,x[j].S);
			j++;
		}
		ans[qu[i].idx] += qu[i].f*query(1,0,n-1,qu[i].a,qu[i].b);
	}

	for(int i=0;i<q;i++) cout << ans[i] << endl;
}