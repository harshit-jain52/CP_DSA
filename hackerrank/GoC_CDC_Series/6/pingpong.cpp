#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 2;

int fact[2 * N], fact_inv[2 * N];

int binpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

ll solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    if (x < y)
        swap(x, y);

    if (x < n || x - y <= 1)
        return 0;

    if (x == n)
        return (fact[x + y - 1] * 1LL * ((fact_inv[y] * 1LL * fact_inv[x - 1]) % M)) % M;
    else
    {
        if (x - y != 2)
            return 0;
        else
        {
            int ans = (fact[2 * n - 2] * 1LL * ((fact_inv[n - 1] * 1LL * fact_inv[n - 1]) % M)) % M;
            ans = (ans * 1LL * binpow(2, y - (n - 1))) % M;
            return ans;
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;

    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i < 2 * N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % M;
        fact_inv[i] = binpow(fact[i], M - 2);
    }

    while (t--)
        cout << solve() << endl;
}