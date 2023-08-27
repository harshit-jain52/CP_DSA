#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int N = 2e5;

int arr[N];
int seg[4 * N];

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

    int len = hi - lo + 1;
    int pow;

    for (int i = 1; i <= 17; i++)
    {
        if ((1 << i) == len)
        {
            pow = i;
            break;
        }
    }

    if (pow % 2 == 0)
        seg[idx] = (seg[2 * idx + 1] ^ seg[2 * idx + 2]);
    else
        seg[idx] = (seg[2 * idx + 1] | seg[2 * idx + 2]);
}

void update(int idx, int lo, int hi, int i, int val)
{
    if (lo == hi)
    {
        seg[idx] = val;
        return;
    }

    int mid = (lo + hi) / 2;

    if (i <= mid)
        update(2 * idx + 1, lo, mid, i, val);
    else
        update(2 * idx + 2, mid + 1, hi, i, val);

    int len = hi - lo + 1;
    int pow;
    
    for (int i = 1; i <= 17; i++)
    {
        if ((1 << i) == len)
        {
            pow = i;
            break;
        }
    }

    if (pow % 2 == 0)
        seg[idx] = (seg[2 * idx + 1] ^ seg[2 * idx + 2]);
    else
        seg[idx] = (seg[2 * idx + 1] | seg[2 * idx + 2]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int num = (1 << n);

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    build(0, 0, num - 1);

    // for (int i = 0; i < 4 * num; i++)
    // {
    //     cout << seg[i] << " ";
    // }
    // cout << endl;

    while (m--)
    {
        int p, b;
        cin >> p >> b;

        update(0, 0, num - 1, p - 1, b);
        cout << seg[0] << endl;
    }
}