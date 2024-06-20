#include <bits/stdc++.h>
using namespace std;
const int N =2e5+5;

int seg[4*N];

void build(int id, int l, int r){
    if(l>r) return;
    if(l==r){
        seg[id]=1;
        return;
    }
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    seg[id] = seg[id<<1]+seg[id<<1|1];
}

void update(int id, int l, int r, int k, int &x){
    if(l==r){
        x = l;
        seg[id]=0;
        return;
    }
    
    int mid = (l+r)/2;
    if(seg[id<<1]>=k) update(id<<1,l,mid,k,x);
    else update(id<<1|1,mid+1,r,k-seg[id<<1],x);
    seg[id] = seg[id<<1]+seg[id<<1|1];
}

int main(){
    int n; cin >> n;
    int indx[n], id[n], ans[n];
    for(int i=0;i<n;i++) cin >> indx[i];
    for(int i=0;i<n;i++) cin >> id[i];
    build(1,0,n-1);
    
    for(int i=n-1;i>=0;i--){
        int x=indx[i];
        update(1,0,n-1,indx[i]+1,x);
        ans[x] = id[i];
    }
    for(int i=0;i<n;i++) cout << ans[i]<<" ";
}