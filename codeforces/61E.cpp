#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 2;

int arr[N];
vector<int> seg[4 * N];

vector<int> merge(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    vector<int> res;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }

    while (i < n)
        res.push_back(a[i++]);
    while (j < m)
        res.push_back(b[j++]);

    return res;
}

void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        vector<int> temp{arr[l]};
        seg[id] = temp;
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

int lessThan(int id, int l, int r, int lq, int rq, int x)
{
    if (lq > r || rq < l)
        return 0;

    if (lq <= l && rq >= r)
        return (upper_bound(seg[id].begin(), seg[id].end(), x) - seg[id].begin());

    int mid = (l + r) / 2;
    return (lessThan(id << 1, l, mid, lq, rq, x) + lessThan(id << 1 | 1, mid + 1, r, lq, rq, x));
}

int moreThan(int id, int l, int r, int lq, int rq, int x)
{
    if (lq > r || rq < l)
        return 0;

    if (lq <= l && rq >= r)
        return (seg[id].end() - upper_bound(seg[id].begin(), seg[id].end(), x));

    int mid = (l + r) / 2;
    return (moreThan(id << 1, l, mid, lq, rq, x) + moreThan(id << 1 | 1, mid + 1, r, lq, rq, x));
}

int main()
{
    FASTIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);
    ll ct = 0;
    for (int j = 1; j < n - 1; j++)
    {
        ct += (moreThan(1, 0, n - 1, 0, j - 1, arr[j]) * 1LL * lessThan(1, 0, n - 1, j + 1, n - 1, arr[j]));
    }
    cout << ct;
}