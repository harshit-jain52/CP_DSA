#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int arr[N], lazy[4 * N];

void build(int idx, int lo, int hi)
{
    lazy[idx] = 0;
    if (lo == hi)
    {
        lazy[idx] = arr[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);
}

void update(int idx, int lo, int hi, int l, int r, int val)
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
        update(2 * idx + 1, lo, mid, l, r, val);
        update(2 * idx + 2, mid + 1, hi, l, r, val);
    }
}

void query(int idx, int lo, int hi, int i)
{
    if (lo > i || hi < i)
        return;

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

int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            arr[i] = 0;
        }

        build(0, 0, n - 1);

        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int l, r;
                cin >> l >> r;
                update(0, 0, n - 1, l - 1, r - 1, 1);
            }
            else
            {
                int x;
                cin >> x;
                query(0, 0, n - 1, x - 1);

                int op = arr[x - 1];

                int num = a[x - 1];
                while (op-- && num != sumOfDigits(num))
                {
                    num = sumOfDigits(num);
                }

                cout << num << endl;
            }
        }
    }
}