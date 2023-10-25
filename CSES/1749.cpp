#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

ll arr[N], seg[4 * N];

void build(int idx, int lo, int hi)
{
    if (lo > hi)
        return;

    if (lo == hi)
    {
        seg[idx] = 1;
        return;
    }

    int mid = (lo + hi) / 2;

    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

void update(int idx, int lo, int hi, int pos, int &getNum)
{
    if (lo > hi)
        return;

    if (lo == hi)
    {
        getNum = arr[lo];
        seg[idx] = 0;
        return;
    }

    int mid = (lo + hi) / 2;

    if (seg[2 * idx + 1] >= pos)
        update(2 * idx + 1, lo, mid, pos, getNum);
    else
        update(2 * idx + 2, mid + 1, hi, pos - seg[2 * idx + 1], getNum);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n - 1);

    int num = -1;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        update(0, 0, n - 1, p, num);
        cout << num << " ";
    }
}