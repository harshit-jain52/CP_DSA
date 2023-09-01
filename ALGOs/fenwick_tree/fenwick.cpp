#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5;

// Binary Indexed Tree
// 1-based indexing

ll fen[N];

/*
Query Types:
1. Point Updates (Assignment)
2. Range Sum
*/

// ith index stores sum of elements from (j+1) to i, where j is no. we get after removing last set bit in i

void update(int i, ll val) // O(logN)
{
    for (; i < N; i += (i & -i))
        fen[i] += val;
}

// sum from 0 to ith index
ll sum(int i) // O(logN)
{
    ll ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += fen[i];

    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n+10];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(i, a[i]);
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i;
            ll x;
            cin >> i >> x;
            update(i, x - a[i]);
            a[i] = x;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << endl;
        }
    }
}