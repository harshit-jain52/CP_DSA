#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
const int LOG = 20;

struct Query{
	int a,b,w,idx;
	Query(){}

	bool operator<(Query other){
		return w < other.w;
	}
};

int in[N], out[N], up[N][20], depth[N];
vector<int>g[N];
ll seg[8*N];
int timer = 0;

void dfs(int v, int pp, int dep){
	in[v]=timer++;
	depth[v]=dep;
	up[v][0]=pp;

	for(int i=1;i<LOG;i++) up[v][i]=up[up[v][i-1]][i-1];;

	for(int ch: g[v]) if(ch!=pp) dfs(ch,v,dep+1);

	out[v]=timer++;
}

int LCA(int u, int v){
	if(depth[u]<depth[v]) swap(u,v);

	for(int i=LOG-1;i>=0;i--){
		if((depth[u]-depth[v])&(1<<i)) u = up[u][i];
	}

	if(u==v) return u;

	for(int i=LOG-1;i>=0;i--){
		if(up[u][i]!=up[v][i]){
			u=up[u][i];
			v=up[v][i];
		}
	}

	return up[u][0];
}

void update(int id, int l, int r, int pos, int val){
	if(l>r || l>pos || pos>r) return;
	if(l==r){
		seg[id]=val;
		return;
	}

	int mid = (l+r)/2;
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	seg[id]=seg[id<<1]+seg[id<<1|1];
}

ll query(int id, int l, int r, int pos){
	if(l>r || l>pos) return 0;
	if(r<=pos) return seg[id];

	int mid = (l+r)/2;
	return (query(id<<1,l,mid,pos)+query(id<<1|1,mid+1,r,pos));
}

int main()
{
	FASTIO
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int arr[n+1];
	vector<pair<int,int>>a(n);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		a[i-1].F = arr[i];
		a[i-1].S = i;
	}

	dfs(1,0,0);

	vector<Query>qu(q);
	for(int i=0;i<q;i++){
		cin >> qu[i].a>>qu[i].b>>qu[i].w;
		qu[i].idx=i;
	}

	sort(a.begin(),a.end());
	sort(qu.begin(),qu.end());

	int i=0,j=0;
	ll ans[q];
	for(i=0;i<q;i++){
		while(j<n && a[j].F<=qu[i].w){
			update(1,0,2*n-1,in[a[j].S],a[j].F);
			update(1,0,2*n-1,out[a[j].S],-a[j].F);
			j++;
		}

		int lc = LCA(qu[i].a, qu[i].b);

		ll to_a = query(1,0,2*n-1,in[qu[i].a]);
		ll to_b = query(1,0,2*n-1,in[qu[i].b]);
		ll to_l = query(1,0,2*n-1,in[lc]);

		ans[qu[i].idx] = to_a + to_b - 2*to_l;
		if(arr[lc]<=qu[i].w) ans[qu[i].idx]+=arr[lc];
	}

	for(i=0;i<q;i++) cout << ans[i]<<endl;
}