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

int range_sum(int idx, int lo, int hi, int l, int r)
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
        seg[idx] += val;
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

    int n;
    cin >> n;

    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    euler_tour(1, 0);

    int a[n];
    vector<pair<pair<int, int>, int>> vec;
    for (int i = 1; i <= n; i++)
    {
        int l = startTime[i], r = endTime[i] - 1;
        a[l] = c[i-1];
        vec.push_back({{r, l}, i - 1});
    }

    sort(vec.begin(), vec.end());

    map<int, int> lastIdx;
    int curr = 0, ans[n];

    for (int i = 0; i < n && curr < n; i++)
    {
        if (lastIdx.find(a[i]) != lastIdx.end())
        {
            point_update(0, 0, n - 1, lastIdx[a[i]], -1);
        }
        lastIdx[a[i]] = i;
        point_update(0, 0, n - 1, lastIdx[a[i]], 1);

        while (vec[curr].first.first == i && curr < n)
        {
            ans[vec[curr].second] = range_sum(0, 0, n - 1, vec[curr].first.second, vec[curr].first.first);
            curr++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}