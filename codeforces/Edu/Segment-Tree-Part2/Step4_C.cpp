#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e6+5;
#define F first
#define S second

struct node{
    int bl, ct;
    bool left,right;
    int lz;
    node(){bl=ct=left=right=0;lz=-1;}
};

node seg[4*N];

node merge(node a, node b){
    node tmp;
    tmp.bl = a.bl+b.bl;
    tmp.ct = a.ct + b.ct - a.right*b.left;
    tmp.left = a.left;
    tmp.right = b.right;
    return tmp;
}

void push(int id, int l, int r){
    if(seg[id].lz!=-1){
        int x = seg[id].lz; // 0-white,1-black
        seg[id].left=seg[id].right=seg[id].ct=x;
        seg[id].bl = x*(r-l+1);

        if(l!=r){
            seg[id<<1].lz = x;
            seg[id<<1|1].lz = x;
        }

        seg[id].lz = -1;
    }
}

void update(int id, int l, int r, int lq, int rq, bool col){
    push(id,l,r);
    if(lq>r || l>rq) return;
    if(l>=lq && r<=rq){
        seg[id].lz = col;
        push(id,l,r);
        return;
    }

    int mid = (l+r)/2;
    update(id<<1,l,mid,lq,rq,col);
    update(id<<1|1,mid+1,r,lq,rq,col);
    seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

int main()
{
    FASTIO
    int n; cin >> n;
    int minx=INT_MAX,maxx=INT_MIN;
    vector<pair<bool,pair<int,int>>>qu;

    for(int i=0;i<n;i++){
        char c; int x,l; cin >> c >> x >> l;
        minx = min(minx,x);
        maxx=max(maxx,x+l-1);
        qu.push_back({c=='B',{x,x+l-1}});
    }

    for(int i=0;i<n;i++){
        update(1,0,maxx-minx,qu[i].S.F-minx,qu[i].S.S-minx,qu[i].F);
        // cout << qu[i].S.F << " "<<qu[i].S.S<<" "<<qu[i].F<<endl;
        cout << seg[1].ct << " "<<seg[1].bl<<endl;
    }
}