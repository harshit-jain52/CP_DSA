#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;
const int P = 31;

int p_pow[N];

struct node
{
    int hash, sz;
    node() { hash = sz = 0; }
};

node merge(node a, node b)
{
    node tmp;
    tmp.sz = a.sz + b.sz;
    tmp.hash = (a.hash + (p_pow[a.sz] * 1LL * b.hash) % M) % M;
    return tmp;
}

struct SegTree
{
    string s;
    vector<node> vec;
    SegTree(string str) : s(str)
    {
        vec.assign(4 * (int)str.size() + 10, node());
    }

    void build(int id, int l, int r)
    {
        if (l > r)
            return;
        if (l == r)
        {
            vec[id].sz = 1;
            vec[id].hash = (s[l] - 'a' + 1);
            return;
        }

        int mid = (l + r) / 2;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        vec[id] = merge(vec[id << 1], vec[id << 1 | 1]);
    }

    void update(int id, int l, int r, int pos, char c)
    {
        if (l > r || l > pos || pos > r)
            return;
        if (l == r)
        {
            s[l] = c;
            vec[id].hash = (s[l] - 'a' + 1);
            return;
        }

        int mid = (l + r) / 2;
        update(id << 1, l, mid, pos, c);
        update(id << 1 | 1, mid + 1, r, pos, c);
        vec[id] = merge(vec[id << 1], vec[id << 1 | 1]);
    }

    node query(int id, int l, int r, int lq, int rq)
    {
        if (l > r || lq > r || l > rq)
            return node();
        if (l >= lq && r <= rq)
            return vec[id];

        int mid = (l + r) / 2;
        return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
    }
};

int main()
{
    FASTIO
    p_pow[0] = 1;
    for (int i = 1; i < N; i++)
    {
        p_pow[i] = (P * 1LL * p_pow[i - 1]) % M;
    }

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    SegTree seg(s);
    reverse(s.begin(), s.end());
    SegTree rseg(s);

    seg.build(1, 0, n - 1);
    rseg.build(1, 0, n - 1);

    while (m--)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int k;
            char x;
            cin >> k >> x;
            seg.update(1, 0, n - 1, k - 1, x);
            rseg.update(1, 0, n - 1, n - k, x);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            int h1 = seg.query(1, 0, n - 1, a - 1, b - 1).hash;
            int h2 = rseg.query(1, 0, n - 1, n - b, n - a).hash;
            cout << ((h1 == h2) ? "YES" : "NO") << endl;
        }

        // cout << seg.s << " "<<rseg.s<<endl;
    }
}