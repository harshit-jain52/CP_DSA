#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 10;

int timer = 0;
vector<int> tree[N];
vector<int> startTime(N, 0);
vector<int> endTime(N, 0);
ll arr[N], seg[4 * N];

void euler_tour(int v, int par)
{
    startTime[v] = timer++;

    for (int child : tree[v])
    {
        if (child == par)
            continue;

        euler_tour(child, v);
    }
    endTime[v] = timer;
}

void build(int idx, int lo, int hi)
{
    if (lo > hi)
        return;
    if (lo == hi)
    {
        seg[idx] = arr[lo];
        return;
    }

    int mid = (lo + hi) / 2;

    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

ll range_sum(int idx, int lo, int hi, int l, int r)
{
    if (r < lo || l > hi || r < l)
        return 0;

    if (lo >= l && hi <= r)
        return seg[idx];

    int mid = (lo + hi) / 2;

    return range_sum(2 * idx + 1, lo, mid, l, r) + range_sum(2 * idx + 2, mid + 1, hi, l, r);
}

void point_update(int idx, int lo, int hi, int i, ll val)
{
    if (lo == hi)
    {
        seg[idx] = val;
        return;
    }

    int mid = (lo + hi) / 2;

    if (i <= mid)
        point_update(2 * idx + 1, lo, mid, i, val);
    else
        point_update(2 * idx + 2, mid + 1, hi, i, val);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    ll val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    euler_tour(1, 0);

    for (int i = 1; i <= n; i++)
        arr[startTime[i]] = val[i - 1];

    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    // for (int i = 1; i <= n; i++)
    //     cout << startTime[i] << " " << endTime[i] << endl;
    
    build(0, 0, n - 1);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int s;
            ll x;
            cin >> s >> x;

            point_update(0, 0, n - 1, startTime[s], x);
        }
        else
        {
            int s;
            cin >> s;
            int len = endTime[s] - startTime[s];

            cout << range_sum(0, 0, n - 1, startTime[s], startTime[s] + len - 1) << endl;
        }
    }
}