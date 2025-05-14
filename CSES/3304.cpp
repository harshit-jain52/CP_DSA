#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

struct Query {
    int a,b,idx;
    bool operator<(Query other) const{	
    	if(a == other.a) return b < other.b; 
        return a < other.a;
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

	int h[n];
	for(int i=0;i<n;i++) cin >> h[i];

	vector<Query>qu(q);
	for(int i=0;i<q;i++){
		cin >> qu[i].a >> qu[i].b;
		qu[i].a--;
		qu[i].b--;
		qu[i].idx=i;
	}
	sort(qu.begin(),qu.end());

	vector<vector<int>>revpge(n);
	stack<int>st;
	for(int i=0;i<n;i++){
		while(!st.empty() && h[st.top()]<h[i]) st.pop();
		if(!st.empty()) revpge[st.top()].push_back(i);
		else update(1,0,n-1,i);
		st.push(i);
	}

	vector<int>ans(q);
	int j=0;
	for(int i=0;i<q;i++){
		while(j<qu[i].a){
			for(int pos: revpge[j]) update(1,0,n-1,pos);
			j++;
		}
		ans[qu[i].idx] = query(1,0,n-1,qu[i].a,qu[i].b);
	}

	for(int i=0;i<q;i++) cout << ans[i] << endl;
}