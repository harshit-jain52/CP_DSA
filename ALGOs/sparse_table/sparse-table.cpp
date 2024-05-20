#include <bits/stdc++.h>
using namespace std;

// Sparse Table
// Range Query, No Updates

const int N = 2e5 + 5;
const int LOG = 18;
int m[N][LOG];
int binLog[N];

int f(int a, int b)
{
    int ans;
    // Idempotent functions, i.e., overlap-friendly
    // e.g. min, max, or, and, gcd
    return ans;
}

int query(int L, int R)
{
    int k = binLog[R - L + 1];
    return f(m[L][k], m[R - (1 << k) + 1][k]);
}

int main()
{
    int n, q;
    cin >> n >> q;

    binLog[1] = 0;
    for (int i = 2; i <= n; i++)
        binLog[i] = 1 + binLog[i / 2];

    for (int i = 0; i < n; i++)
        cin >> m[i][0];

    // Preprocessing - O(NlogN)
    for (int j = 1; j <= binLog[n]; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            m[i][j] = f(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--)
    {
        // Query - O(1)
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
}