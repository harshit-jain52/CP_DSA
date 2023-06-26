#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 3e5 + 10;
int seg[4 * N];
int ans[N];

void fight(int winner, int l, int r, int lo, int hi, int idx)
{
    if (hi < l || lo > r)
        return;

    if (seg[idx] != -1)
        return;

    if (lo >= l && hi <= r)
    {
        seg[idx] = winner;
        return;
    }

    int mid = (lo + hi) / 2;

    fight(winner, l, r, lo, mid, 2 * idx + 1);
    fight(winner, l, r, mid + 1, hi, 2 * idx + 2);
}

void assign(int winner, int idx, int lo, int hi)
{
    if (seg[idx] == -1)
        seg[idx] = winner;

    if (lo == hi)
    {
        ans[lo] = seg[idx];
        return;
    }

    int mid = (lo + hi) / 2;
    assign(seg[idx], 2 * idx + 1, lo, mid);
    assign(seg[idx], 2 * idx + 2, mid + 1, hi);
}
int main()
{
    memset(seg, -1, sizeof(seg));
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l = l - 1, r = r - 1, x = x - 1; // 0-based indexing
        if (x != r)
            fight(x, x + 1, r, 0, n - 1, 0);
        if (x != l)
            fight(x, l, x - 1, 0, n - 1, 0);
    }

    assign(seg[0], 0, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
}