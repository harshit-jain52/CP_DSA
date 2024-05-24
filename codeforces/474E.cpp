#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 5;

int seg[4 * N];

void update(int id, int l, int r, int pos, int val)
{
    if (l > r || l > pos || r < pos)
        return;
    if (l == r)
    {
        seg[id] = max(seg[id], val);
        return;
    }

    int mid = (l + r) / 2;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

int query(int id, int l, int r, int lq, int rq)
{
    if (l > r || l > rq || lq > r)
        return 0;
    if (l >= lq && r <= rq)
        return seg[id];

    int mid = (l + r) / 2;
    return max(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
}

int main()
{
    FASTIO
    int n, d;
    cin >> n >> d;
    ll h[n];
    map<ll, int> comp;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        comp[h[i]];
    }

    int ct = 0;
    for (auto &v : comp)
        v.second = ct++;

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        auto it = comp.upper_bound(h[i] - d);
        if (it != comp.begin())
        {
            it--;
            int lo = it->second;
            dp[i] = max(dp[i], 1 + query(1, 0, ct - 1, 0, lo));
        }

        it = comp.lower_bound(h[i] + d);
        if (it != comp.end())
        {
            int hi = it->second;
            dp[i] = max(dp[i], 1 + query(1, 0, ct - 1, hi, ct - 1));
        }

        update(1, 0, ct - 1, comp[h[i]], dp[i]);
    }

    int len = 0, start = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > len)
        {
            len = dp[i];
            start = i;
        }
    }

    cout << len << endl;

    vector<int> vec(len + 1);
    vec[len] = start;
    len--;
    for (int i = start - 1; i >= 0; i--)
    {
        if (dp[i] == len && abs(h[i] - h[vec[len + 1]]) >= d)
        {
            vec[len] = i;
            len--;
        }
    }

    for (int i = 1; i < vec.size(); i++)
        cout << vec[i] + 1 << " ";
}