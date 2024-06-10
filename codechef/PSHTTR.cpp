#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct Edge{
	int u,v,c;
	Edge(){}

	bool operator<(Edge other){
		return c < other.c;
	}
};

struct Query{
	int idx,u,v,k;
	Query(){}

	bool operator<(Query other){
		return k < other.k;
	}
};

vector<int>g[N];
int in[N],out[N];
vector<int>seg;
int timer;

void dfs(int v, int pp){
	in[v]=timer++;
	for(int ch: g[v]) if(ch!=pp) dfs(ch,v);
	out[v]=timer++;
}

void reset(int n){
	timer=0;
	for(int i=0;i<=n;i++) g[i].clear();
	seg.assign(8*n+10,0);
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
	seg[id] = (seg[id<<1]^seg[id<<1|1]);
}

int query(int id, int l, int r, int pos){
	if(l>r || l>pos) return 0;
	if(r<=pos) return seg[id];

	int mid=(l+r)/2;
	return (query(id<<1,l,mid,pos)^query(id<<1|1,mid+1,r,pos));
}

void solve(){
	int n; cin >> n;
	reset(n);

	vector<Edge>e(n-1);
	for(int i=0;i<n-1;i++){
		cin >> e[i].u >> e[i].v >> e[i].c;
		g[e[i].u].push_back(e[i].v);
		g[e[i].v].push_back(e[i].u);
	}

	sort(e.begin(),e.end());

	int m; cin >> m;
	vector<Query>q(m);
	for(int i=0;i<m;i++) {cin >> q[i].u>>q[i].v>>q[i].k; q[i].idx=i;}

	sort(q.begin(),q.end());

	dfs(1,0);

	int ans[m];
	int i=0,j=0;
	for(i=0;i<m;i++){
		while(j<n-1 && q[i].k>=e[j].c){
			if(in[e[j].u]<in[e[j].v]) swap(e[j].u,e[j].v);
			update(1,0,2*n-1,in[e[j].u],e[j].c);
			update(1,0,2*n-1,out[e[j].u],e[j].c);
			j++;
		}

		ans[q[i].idx]=(query(1,0,2*n-1,in[q[i].u])^query(1,0,2*n-1,in[q[i].v]));
	}

	for(i=0;i<m;i++) cout << ans[i] << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}