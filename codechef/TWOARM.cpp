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

class Kingdom
{
    vector<int> seg;

public:
    vector<ll> st;

    Kingdom(int sz)
    {
        st.resize(sz);
        seg.resize(4 * sz + 4, 0);
    }

    int pref(int id, int l, int r, int rq)
    {
        if (l > r || l > rq)
            return 0;
        if (r <= rq)
            return seg[id];

        int mid = (l + r) / 2;
        return pref(id << 1, l, mid, rq) + pref(id << 1 | 1, mid + 1, r, rq);
    }

    void update(int id, int l, int r, int pos, int val)
    {
        if (l > r || l > pos || pos > r)
            return;
        if (l == r)
        {
            seg[id] += val;
            return;
        }
        int mid = (l + r) / 2;
        update(id << 1, l, mid, pos, val);
        update(id << 1 | 1, mid + 1, r, pos, val);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
};

int main()
{
    FASTIO
    int n, m, q;
    cin >> n >> m >> q;
    Kingdom k1(n), k2(m);

    for (int i = 0; i < n; i++)
        cin >> k1.st[i];
    for (int i = 0; i < m; i++)
        cin >> k2.st[i];

    // for(int i=0;i<n;i++) cout << k1.st[i]<<" ";
    // for(int i=0;i<m;i++) cout << k2.st[i]<<" ";

    while (q--)
    {
        int a, b, c, d, k, pos;
        cin >> a >> b >> c >> d >> k >> pos;

        if (k == 1)
        {
            k1.update(1, 0, n - 1, a - 1, 1);
            k1.update(1, 0, n - 1, b, -1);
            k2.update(1, 0, m - 1, c - 1, -1);
            k2.update(1, 0, m - 1, d, 1);
            cout << (k1.pref(1, 0, n - 1, pos - 1) + 1) * k1.st[pos - 1] << endl;
        }
        else
        {
            k1.update(1, 0, n - 1, a - 1, -1);
            k1.update(1, 0, n - 1, b, 1);
            k2.update(1, 0, m - 1, c - 1, 1);
            k2.update(1, 0, m - 1, d, -1);
            cout << (k2.pref(1, 0, m - 1, pos - 1) + 1) * k2.st[pos - 1] << endl;
        }
    }
}