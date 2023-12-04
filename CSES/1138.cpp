#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 10;

int timer = 0;
vector<int> tree[N];
vector<int> startTime(N, 0);
vector<int> endTime(N, 0);
ll val[N], arr[N], lazy[4 * N];

void euler_tour(int v, int par, ll pathsum)
{
    startTime[v] = timer++;
    arr[startTime[v]] = pathsum + val[v];

    for (int child : tree[v])
    {
        if (child == par)
            continue;

        euler_tour(child, v, pathsum + val[v]);
    }
    endTime[v] = timer;
}

void build(int idx, int lo, int hi)
{
    lazy[idx] = 0;
    if (lo == hi)
    {
        return;
    }

    int mid = (lo + hi) / 2;
    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);
}

void range_update(int idx, int lo, int hi, int l, int r, ll val)
{

    if (lazy[idx] != 0 && lo != hi)
    {
        lazy[2 * idx + 1] += lazy[idx];
        lazy[2 * idx + 2] += lazy[idx];
        lazy[idx] = 0;
    }

    if (lo > r || hi < l)
        return;

    if (lo >= l && hi <= r)
    {
        lazy[idx] += val;
    }
    else
    {
        int mid = (lo + hi) / 2;
        range_update(2 * idx + 1, lo, mid, l, r, val);
        range_update(2 * idx + 2, mid + 1, hi, l, r, val);
    }
}

void query(int idx, int lo, int hi, int i)
{
    if (lo > i || hi < i)
    {
        return;
    }

    if (lo == hi)
    {
        arr[lo] += lazy[idx];
        lazy[idx] = 0;
        return;
    }

    if (lazy[idx] != 0)
    {
        lazy[2 * idx + 1] += lazy[idx];
        lazy[2 * idx + 2] += lazy[idx];
        lazy[idx] = 0;
    }
    int mid = (lo + hi) / 2;
    query(2 * idx + 1, lo, mid, i);
    query(2 * idx + 2, mid + 1, hi, i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
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

    euler_tour(1, 0, 0);
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

            range_update(0, 0, n - 1, startTime[s], endTime[s] - 1, x - val[s]);
            val[s] = x;
        }
        else
        {
            int s;
            cin >> s;

            query(0, 0, n - 1, startTime[s]);
            cout << arr[startTime[s]] << endl;
        }
    }
}