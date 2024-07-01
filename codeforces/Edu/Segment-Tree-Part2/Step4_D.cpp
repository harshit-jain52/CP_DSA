#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

struct node{
    ll wtsum,sum,lz;
    node(){wtsum=sum=lz=0;}
};

ll arr[N];
node seg[4*N];

node merge(node a, node b){
    node tmp;
    tmp.wtsum = a.wtsum + b.wtsum;
    tmp.sum = a.sum+b.sum;
    return tmp;
}

void build(int id, int l, int r){
    if(l>r) return;
    if(l==r){
        seg[id].sum = arr[l];
        seg[id].wtsum = (l+1)*arr[l];
        return;
    }

    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

void push(int id, int l, int r){
    if(seg[id].lz){
        seg[id].sum += (r-l+1)*seg[id].lz;
        ll num = (r+1)*1LL*(r+2)/2 - l*1LL*(l+1)/2;
        seg[id].wtsum += num*seg[id].lz;

        if(l!=r){
            seg[id<<1].lz += seg[id].lz;
            seg[id<<1|1].lz += seg[id].lz;
        }

        seg[id].lz=0;
    }
}

void update(int id, int l, int r, int lq, int rq, int d){
    push(id,l,r);
    if(l>rq || lq>r) return;
    if(l>=lq && r<=rq){
        seg[id].lz=d;
        push(id,l,r);
        return;
    }

    int mid = (l+r)/2;
    update(id<<1,l,mid,lq,rq,d);
    update(id<<1|1,mid+1,r,lq,rq,d);
    seg[id]=merge(seg[id<<1],seg[id<<1|1]);
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
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++) cin >> arr[i];
    build(1,0,n-1);

    while(m--){
        int tp,l,r; cin >> tp >> l >> r;
        if(tp==1){
            int d; cin >> d;
            update(1,0,n-1,l-1,r-1,d);
        }
        else{
            node tmp = query(1,0,n-1,l-1,r-1);
            cout << tmp.wtsum - (l-1)*tmp.sum << endl;
        }
    }    
}