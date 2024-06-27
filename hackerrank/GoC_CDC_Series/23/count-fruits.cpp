#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+4;

int arr[N];
bitset<1001> seg[4*N];

void build(int id, int l, int r){
    if(l>r) return;
    if(l==r){
        seg[id].set(arr[l]);
        return;
    }
    
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    seg[id]=seg[id<<1]^seg[id<<1|1];
}

void update(int id, int l, int r, int pos, int v){
    if(l>r || l>pos || pos>r) return;
    if(l==r){
        seg[id].reset(arr[l]);
        arr[l]=v;
        seg[id].set(arr[l]);
        return;
    }
    
    int mid = (l+r)/2;
    update(id<<1,l,mid,pos,v);
    update(id<<1|1,mid+1,r,pos,v);
    seg[id]=seg[id<<1]^seg[id<<1|1];
}

bitset<1001> query(int id, int l, int r, int lq, int rq){
    if(l>r || lq>r || l>rq) return bitset<1001>();
    if(l>=lq && r<=rq) return seg[id];
    
    int mid = (l+r)/2;
    return (query(id<<1,l,mid,lq,rq)^query(id<<1|1,mid+1,r,lq,rq));
}

int main(){
    int n,q; cin >> n >> q;
    for(int i=0;i<n;i++) cin >> arr[i];
    
    build(1,0,n-1);
    
    while(q--){
        int tp,l,r; cin >> tp >> l >> r;
        
        if(tp==1) update(1,0,n-1,l-1,r);
        else cout << query(1,0,n-1,l-1,r-1).count() << endl;
    }
}