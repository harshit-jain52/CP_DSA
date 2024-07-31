#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+5;
const int P = 31;
#define F first
#define S second
 
int p_pow[N], p_pow_inv[N];

int binExp(int a, int b){
    int ans=1;
    while(b){
        a=(a*1LL*a)%M;
        if(b&1) ans=(ans*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

struct Treap{
    char data;
    int priority, subTreeSz, hash;
    pair<Treap*,Treap*>kids;
 
    Treap(char val): data(val), priority(rand()), kids({nullptr,nullptr}),subTreeSz(1) {
        hash = (val-'a'+1);
    }
};
 
 
inline int size(Treap *me) {
    return me ? me->subTreeSz : 0;
}

inline int roll_hash(Treap* me){
    return me ? me->hash : 0;
}

inline void recalc(Treap *me) {
    if(!me) return;
    int szl = size(me->kids.F);
    int szr = size(me->kids.S);
    int hl = roll_hash(me->kids.F);
    int hr = roll_hash(me->kids.S);

    me->subTreeSz = 1+szl+szr;
    me->hash = ((hl+(p_pow[szl]*(me->data -'a'+1))%M)%M + (p_pow[szl+1]*1LL*hr)%M)%M;
}
 
 
pair<Treap*,Treap*> split(Treap* me, int nInLeft){
    if(me==nullptr) return {nullptr,nullptr};
 
    if(size(me->kids.F)>=nInLeft){
        pair<Treap*,Treap*>leftRes = split(me->kids.F,nInLeft);
        me->kids.F = leftRes.S;
        recalc(me);
        return {leftRes.F,me};
    }
    else{
        nInLeft = nInLeft-size(me->kids.F)-1;
        pair<Treap*,Treap*>rightRes = split(me->kids.S,nInLeft);
        me->kids.S = rightRes.F;
        recalc(me);
        return {me,rightRes.S};
    }
 
    return {nullptr,nullptr};
}
 
Treap* merge(Treap* l, Treap* r){
    if(l==nullptr) return r;
    if(r==nullptr) return l;
 
    if(l->priority < r->priority){
        l->kids.S = merge(l->kids.S,r);
        recalc(l);
        return l;
    }
    else{
        r->kids.F = merge(l,r->kids.F);
        recalc(r);
        return r;
    }
 
    return nullptr;
}

void deleteTreap(Treap *me){
    if(me==nullptr) return;
    deleteTreap(me->kids.F);
    deleteTreap(me->kids.S);
}

Treap* rangeDelete(Treap* me, int lq, int rq){
    auto a = split(me,lq-1);
    auto b = split(a.S,rq-lq+1);
    deleteTreap(b.F);
    return merge(a.F,b.S);
}

Treap* insertTreap(Treap* me, char c, int pos){
    auto a = split(me,pos-1);
    return merge(merge(a.F,new Treap(c)),a.S);
}

int rangeHash(Treap*&me, int lq, int rq){
    auto a = split(me,lq-1);
    auto b = split(a.S,rq-lq+1);
    int h = ((b.F)?b.F->hash:0);
    me  = merge(a.F,merge(b.F,b.S));
    return h;
}

ostream& operator<<(ostream &os, Treap* me){
    if(me==nullptr) return os;
    os << me->kids.F;
    os << me->data;
    os<< me->kids.S;
    return os;
}

int main()
{
    FASTIO

    p_pow[0]=p_pow_inv[0]=1;
    for(int i=1;i<N;i++){
        p_pow[i] = (P*1LL*p_pow[i-1])%M;
        p_pow_inv[i] = binExp(p_pow[i],M-2);
    }

    Treap* root=nullptr;
    Treap* rev=nullptr;
    int n,q;
    cin >> n >> q;
    
    string s; cin >> s;
    for(char c: s) root = merge(root,new Treap(c));
    for(char c: s) rev = merge(new Treap(c),rev);

        
    while(q--){
        int tp; cin >> tp;
        if(tp==1){
            int l,r; cin >> l >> r;
            root = rangeDelete(root, l, r);
            rev = rangeDelete(rev, n-r+1, n-l+1);
            n-=(r-l+1);
            // cout << root << endl;
            // cout << rev << endl;
        }
        else if(tp==2){
            char c; int p; cin >> c >> p;
            n++;
            root = insertTreap(root,c,p);
            rev = insertTreap(rev,c,n-p+1);
            // cout << root << endl;
            // cout << rev << endl;
        }
        else{
            int l,r; cin >> l >> r;
            int h1 = rangeHash(root,l,r);
            int h2 = rangeHash(rev,n-r+1,n-l+1);
            cout << ((h1==h2)?"yes":"no") << endl;
        }
    }
}