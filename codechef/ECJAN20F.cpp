#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

vector<int>g[N];
int in[N],out[N],timer=0;
ll arr[2*N];
ll seg[8*N];

void dfs(int v, int p){
    in[v]=timer++;
    for(int ch: g[v]) if(ch!=p) dfs(ch,v);
    out[v]=timer++;
}

void build(int id, int l, int r){
    if(l>r) return;
    if(l==r){
        seg[id]=arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    seg[id] = seg[id<<1]+seg[id<<1|1];
}

void update(int id, int l, int r, int pos, ll val){
    if(l>r || l>pos || pos>r) return;
    if(l==r){
        seg[id] += val;
        return;
    }
    int mid = (l+r)/2;
    update(id<<1,l,mid,pos,val);
    update(id<<1|1,mid+1,r,pos,val);
    seg[id] = seg[id<<1]+seg[id<<1|1];
}

ll query(int id, int l, int r, int rq){
    if(l>r || l>rq) return 0;
    if(r<=rq) return seg[id];
    int mid = (l+r)/2;
    return query(id<<1,l,mid,rq)+query(id<<1|1,mid+1,r,rq);
}

int main()
{
    FASTIO
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);
    for(int i=1;i<=n;i++){
        int tax; cin >> tax;
        arr[in[i]]=tax;
        arr[out[i]]=-tax;
    }
    arr[in[1]]=arr[out[1]]=0;
    build(1,0,2*n-1);
    while(q--){
        int type, x;
        cin >> type >> x;
        if(type==1) cout << (query(1,0,2*n-1,in[x]))<<endl;
        else{
            int u; cin >> u;
            if(x==1) continue;
            update(1,0,2*n-1,in[x],u);
            update(1,0,2*n-1,out[x],-u);
        }
    }
}