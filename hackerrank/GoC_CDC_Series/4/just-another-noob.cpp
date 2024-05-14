#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int arr[N], seg[4 * N];

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
    int idx1 = 2 * idx + 1;
    int idx2 = idx1 + 1;
    build(idx1, lo, mid);
    build(idx2, mid + 1, hi);
    seg[idx] = seg[idx1] + seg[idx2];
}

void remove(int idx, int lo, int hi, int pos, int &getPos)
{
    if (lo > hi)
        return;
    if (lo == hi)
    {
        getPos = arr[lo];
        seg[idx] = 0;
        return;
    }

    int mid = (lo + hi) / 2;
    int idx1 = 2 * idx + 1;
    int idx2 = idx1 + 1;
    if (seg[idx1] >= pos)
        remove(idx1, lo, mid, pos, getPos);
    else
        remove(idx2, mid + 1, hi, pos - seg[idx1], getPos);
    seg[idx] = seg[idx1] + seg[idx2];
}

int main()
{
    int n;
    cin >> n;
    int ind[n], ans[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        cin >> ind[i];
    }
    build(0, 0, n - 1);
    int ptr = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        remove(0, 0, n - 1, ind[i], ptr);
        ans[ptr] = i + 1;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}