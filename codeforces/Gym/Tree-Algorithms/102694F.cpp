#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

int d[N],in[N],out[N];
ll seg[4*N];
vector<int>g[N];
int timer;

void dfs(int v, int pp, int dep){
    in[v]=timer++;
    d[v] = dep;

    for(int ch: g[v]) if(ch!=pp) dfs(ch,v,dep+1);

    out[v]=timer;
}

void build(int id, int l, int r){
    if(l>r) return;
    if(l==r){
        seg[id]=0;
        return;
    }

    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    seg[id]=seg[id<<1]+seg[id<<1|1];
}

void reset(int n){
    for(int i=1;i<=n;i++) g[i].clear();

    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    timer=0;
    dfs(1,0,0);
    build(1,0,n-1);
}

void update(int id, int l, int r, int pos, int val){
    if(l>r || l>pos || pos>r) return;
    if(l==r){
        seg[id]+=val;
        return;
    }

    int mid = (l+r)/2;
    update(id<<1,l,mid,pos,val);
    update(id<<1|1,mid+1,r,pos,val);
    seg[id]=seg[id<<1]+seg[id<<1|1];
}

ll query(int id, int l, int r, int lq, int rq){
    if(l>r || l>rq || lq>r) return 0;
    if(l>=lq && r<=rq) return seg[id];

    int mid = (l+r)/2;
    return (query(id<<1,l,mid,lq,rq)+query(id<<1|1,mid+1,r,lq,rq));
}

void solve(){
    int n,q; cin >> n >> q;
    reset(n);
    while(q--){
        int a,b,x; cin >> a >> b >> x;
        if(x==0){
            if(d[a]<d[b]) swap(a,b);
            cout << abs(query(1,0,n-1,in[a],out[a]-1)) << endl;
        }
        else{
            update(1,0,n-1,in[a],x);
            update(1,0,n-1,in[b],-x);
        }
    }
}

int main()
{
    FASTIO
    int t; cin >> t;
    while(t--) solve();
}