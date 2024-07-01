#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

struct node{
    ll sum1,sum2;
    node(){sum1=sum2=0;}
};

node seg[4*N];

node merge(node a, node b){
    node tmp;
    tmp.sum1 = a.sum1+b.sum1;
    tmp.sum2 = a.sum2+b.sum2;
    return tmp;
}

void update(int id, int l, int r, int pos, ll val1, ll val2){
    if(l>r || l>pos || pos>r) return;
    if(l==r){
        seg[id].sum1 += val1;
        seg[id].sum2 += val2;
        return;
    }

    int mid = (l+r)/2;
    update(id<<1,l,mid,pos,val1,val2);
    update(id<<1|1,mid+1,r,pos,val1,val2);
    seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}

node query(int id, int l, int r, int rq){
    if(l>r || l>rq) return node();
    if(r<=rq) return seg[id];

    int mid=(l+r)/2;
    return merge(query(id<<1,l,mid,rq),query(id<<1|1,mid+1,r,rq));
}

int main()
{
    FASTIO
    int n,m; cin >> n >> m;
    while(m--){
        int t; cin >> t;
        if(t==1){
            int l,r; ll a,d;
            cin >> l >> r >> a >> d;
            ll v1 = a-d*l, v2 = d;

            update(1,0,n-1,l-1,v1,v2);
            update(1,0,n-1,r,-v1,-v2);
        }
        else{
            int x; cin >> x;
            node tmp = query(1,0,n-1,x-1);
            cout << tmp.sum1 + x*tmp.sum2 << endl;
        }
    }
}