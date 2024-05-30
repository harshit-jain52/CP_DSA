#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
    vector<int>ct;
    node(){ct.assign(26,0);}
};

vector<int>g[N];
int in[N],out[N],timer=0;
char arr[N];
node seg[4*N];

void dfs(int v, int p){
    in[v]=timer++;
    for(int ch: g[v]) if(ch!=p) dfs(ch,v);
    out[v]=timer;
}

bool checkPal(node a){
    int oddct=0;
    for(int i=0;i<26;i++) oddct += a.ct[i]&1;
    return oddct<=1;
}

node merge(node a, node b){
    node tmp;
    for(int i=0;i<26;i++) tmp.ct[i]=a.ct[i]+b.ct[i];
    return tmp;
}

void build(int id, int l, int r){
    if(l>r) return;
    if(l==r){
        seg[id].ct[arr[l]-'a']++;
        return;
    }
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

void update(int id, int l, int r, int pos, char c){
    if(l>r || l>pos || pos>r) return;
    if(l==r){
        seg[id].ct[arr[l]-'a']--;
        arr[l]=c;
        seg[id].ct[arr[l]-'a']++;
        return;
    }
    int mid = (l+r)/2;
    update(id<<1,l,mid,pos,c);
    update(id<<1|1,mid+1,r,pos,c);
    seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq){
    if(l>r || l>rq || lq>r) return node();
    if(l>=lq && r<=rq) return seg[id];
    int mid = (l+r)/2;
    return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

int main()
{
    FASTIO
    int n,m;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);
    for(int i=1;i<=n;i++) cin >> arr[in[i]];
    build(1,0,n-1);
    cin >> m;
    while(m--){
        int type, x;
        cin >> type >> x;
        if(type) cout << (checkPal(query(1,0,n-1,in[x],out[x]-1))?"YES":"NO")<<endl;
        else{
            char c; cin >> c;
            update(1,0,n-1,in[x],c);
        }
    }
}