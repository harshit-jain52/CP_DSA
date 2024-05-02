#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 5;
int fact[N];

int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % M;

        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

void factorial()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (i * 1LL * fact[i - 1]) % M;
}

// Using factorial:
// TC: O(N) precompute, O(logR) query
// SC: O(N)

int nCr_fact(int n, int r)
{
    if (r == 0 || r == n)
        return 1;

    int ans = (fact[n] * 1LL * ((binExp(fact[r], M - 2) * 1LL * binExp(fact[n - r], M - 2)) % M)) % M;
    return ans;
}

// for bigger N:
// TC: O(RlogN) query, SC: O(1)

int nCr(int n, int r)
{
    r = min(r, n - r);
    if (r == 0)
        return 1;

    int ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = (ans * 1LL * (n - i + 1)) % M;      // n(n-1)(n-2)...(n-r+1)
        ans = (ans * 1LL * binExp(i, M - 2)) % M; // r!
    }
}