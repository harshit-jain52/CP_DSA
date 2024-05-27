#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+5;

double seg[4*N];
vector<int>g[N];
int in[N],out[N];
int timer=0;

void dfs(int v, int pp){
    in[v]=timer++;
    for(int ch: g[v]){
        if(ch!=pp) dfs(ch,v);
    }
    out[v]=timer;
}

void update(int id, int l, int r, int pos, int val){
    if(l>r || l>pos || r<pos) return;
    if(l==r){
        seg[id] = log10(val);
        return;
    }

    int mid = (l+r)/2;
    update(id<<1,l,mid,pos,val);
    update(id<<1|1,mid+1,r,pos,val);
    seg[id] = seg[id<<1] + seg[id<<1|1];
}

double query(int id, int l, int r, int lq, int rq){
    if(l>r || l>rq || lq>r) return 0;
    if(l>=lq && r<=rq) return seg[id];

    int mid = (l+r)/2;
    return (query(id<<1,l,mid,lq,rq) + query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
    FASTIO
    cout << fixed<<setprecision(10);

    int n,q;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);
    cin >> q;
    while(q--){
        int t,x,y;
        cin >> t >> x >> y;
        if(t==1) update(1,0,n-1,in[x],y);
        else cout << pow(10.0,min(9.0,query(1,0,n-1,in[x],out[x]-1)-query(1,0,n-1,in[y],out[y]-1))) << endl;
    }
}