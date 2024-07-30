#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
#define F first
#define S second

struct Treap
{
    ll data, sum;
    int priority, subTreeSz, toRev;
    pair<Treap *, Treap *> kids;

    Treap(ll val) : data(val), priority(rand()), kids({nullptr, nullptr}), subTreeSz(1), toRev(0), sum(val) {}
};

inline int size(Treap *me)
{
    return me ? me->subTreeSz : 0;
}

inline void recalc(Treap *me)
{
    if (!me)
        return;
    me->subTreeSz = 1 + size(me->kids.F) + size(me->kids.S);
    me->sum = me->data + ((me->kids.F) ? me->kids.F->sum : 0) + ((me->kids.S) ? me->kids.S->sum : 0);
}

void prop(Treap *me)
{
    if (!me)
        return;
    if (!(me->toRev))
        return;
    swap(me->kids.F, me->kids.S);
    if (me->kids.F)
        me->kids.F->toRev ^= 1;
    if (me->kids.S)
        me->kids.S->toRev ^= 1;
    me->toRev = 0;
}

pair<Treap *, Treap *> split(Treap *me, int nInLeft)
{
    if (me == nullptr)
        return {nullptr, nullptr};
    prop(me);
    if (size(me->kids.F) >= nInLeft)
    {
        pair<Treap *, Treap *> leftRes = split(me->kids.F, nInLeft);
        me->kids.F = leftRes.S;
        recalc(me);
        return {leftRes.F, me};
    }
    else
    {
        nInLeft = nInLeft - size(me->kids.F) - 1;
        pair<Treap *, Treap *> rightRes = split(me->kids.S, nInLeft);
        me->kids.S = rightRes.F;
        recalc(me);
        return {me, rightRes.S};
    }

    return {nullptr, nullptr};
}

Treap *merge(Treap *l, Treap *r)
{
    if (l == nullptr)
        return r;
    if (r == nullptr)
        return l;

    prop(l);
    prop(r);

    if (l->priority < r->priority)
    {
        l->kids.S = merge(l->kids.S, r);
        recalc(l);
        return l;
    }
    else
    {
        r->kids.F = merge(l, r->kids.F);
        recalc(r);
        return r;
    }

    return nullptr;
}

Treap *reverse(Treap *me, int lq, int rq)
{
    pair<Treap *, Treap *> a = split(me, lq - 1);
    pair<Treap *, Treap *> b = split(a.S, rq - lq + 1);
    b.F->toRev ^= 1;
    return merge(a.F, merge(b.F, b.S));
}

ll rangeSum(Treap *&me, int lq, int rq)
{
    pair<Treap *, Treap *> a = split(me, lq - 1);
    pair<Treap *, Treap *> b = split(a.S, rq - lq + 1);
    ll sum = ((b.F) ? b.F->sum : 0);
    me = merge(a.F, merge(b.F, b.S));
    return sum;
}

int main()
{
    FASTIO
    Treap *root = nullptr;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        root = merge(root, new Treap(x));
    }

    while (m--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
            root = reverse(root, a, b);
        else
            cout << rangeSum(root, a, b) << endl;
    }
}