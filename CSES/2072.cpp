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
    char data;
    int priority, subTreeSz;
    pair<Treap *, Treap *> kids;

    Treap(char val) : data(val), priority(rand()), kids({nullptr, nullptr}), subTreeSz(1) {}
};

inline int size(Treap *me)
{
    return me ? me->subTreeSz : 0;
}

inline void recalc(Treap *me)
{
    if (me)
        me->subTreeSz = 1 + size(me->kids.F) + size(me->kids.S);
}

pair<Treap *, Treap *> split(Treap *me, int nInLeft)
{
    if (me == nullptr)
        return {nullptr, nullptr};

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

ostream &operator<<(ostream &os, Treap *me)
{
    if (me == nullptr)
        return os;
    os << me->kids.F;
    os << me->data;
    os << me->kids.S;
    return os;
}

int main()
{
    FASTIO
    Treap *root = nullptr;
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for (char c : s)
        root = merge(root, new Treap(c));

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        auto a = split(root, l - 1);
        auto b = split(a.S, r - l + 1);
        root = merge(merge(a.F, b.S), b.F);
    }

    cout << root;
}