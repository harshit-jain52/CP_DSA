#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

ll arr[N], minseg[4 * N], maxseg[4 * N];

void build(int idx, int lo, int hi)
{
    if (lo > hi)
        return;

    if (lo == hi)
    {
        minseg[idx] = arr[lo];
        maxseg[idx] = arr[lo];
        return;
    }

    int mid = (lo + hi) / 2;

    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);

    minseg[idx] = min(minseg[2 * idx + 1], minseg[2 * idx + 2]);
    maxseg[idx] = max(maxseg[2 * idx + 1], maxseg[2 * idx + 2]);
}

void update(int idx, int lo, int hi, int pos, ll newSal)
{
    if (lo > hi)
        return;

    if (lo == hi)
    {
        minseg[idx] = newSal;
        maxseg[idx] = newSal;
        return;
    }

    int mid = (lo + hi) / 2;
    if (pos <= mid)
        update(2 * idx + 1, lo, mid, pos, newSal);
    else
        update(2 * idx + 2, mid + 1, hi, pos, newSal);

    minseg[idx] = min(minseg[2 * idx + 1], minseg[2 * idx + 2]);
    maxseg[idx] = max(maxseg[2 * idx + 1], maxseg[2 * idx + 2]);
}

void query(int idx, int lo, int hi, ll a, ll b, int &ct)
{
    if (maxseg[idx] < a || minseg[idx] > b || lo > hi)
        return;

    if (maxseg[idx] <= b && minseg[idx] >= a)
    {
        ct += (hi - lo + 1);
        return;
    }

    if (lo == hi)
        return;

    int mid = (lo + hi) / 2;
    query(2 * idx + 1, lo, mid, a, b, ct);
    query(2 * idx + 2, mid + 1, hi, a, b, ct);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n - 1);

    while (q--)
    {
        char c;
        cin >> c;

        if (c == '!')
        {
            int k;
            ll x;

            cin >> k >> x;

            update(0, 0, n - 1, k - 1, x);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            int ct = 0;

            query(0, 0, n - 1, a, b, ct);
            cout << ct << endl;
        }
    }
}