#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
#define F first
#define S second
 
struct Treap{
    int data;
    int priority, subTreeSz;
    pair<Treap*,Treap*>kids;
 
    Treap(int val): data(val), priority(rand()), kids({nullptr,nullptr}),subTreeSz(1) {}
};
 
 
inline int size(Treap *me) {
    return me ? me->subTreeSz : 0;
}
 
inline void recalc(Treap *me) {
    if (me) me->subTreeSz = 1 + size(me->kids.F) + size(me->kids.S);
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
 
ostream& operator<<(ostream &os, Treap* me){
    if(me==nullptr) return os;
    os << me->kids.F;
    os << me->data << " ";
    os<< me->kids.S;
    return os;
}
 
int main()
{
    FASTIO
    Treap* root=nullptr;
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++) root = merge(root,new Treap(i));

    for(int _=1;_<=n;_++){
        int a,b; cin >> a >> b;
        if(a>=b) continue;

        int be=n,ae=n-(b-a);
        if(ae>=b){
            int tmp = ae-b+1;
            be -= tmp;
            ae -= tmp;
        }

        if(ae<a || be<b) continue;

        // cout << a << " "<<b<<" "<<ae<<" "<<be<<endl;
        auto w = split(root,a-1);
        auto x = split(w.S,ae-a+1);
        auto y = split(x.S,b-ae-1);
        auto z = split(y.S,be-b+1);

        root = merge(merge(merge(w.F,z.F),merge(y.F,x.F)),z.S);
    }
 
    cout << root;
}