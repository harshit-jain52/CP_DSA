#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 5;
const int N_ = 4000;
int fact[N];
int pascal[N_][N_];

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

// Using factorial:
// TC: O(N) precompute, O(logR) query
// SC: O(N)
// M must be prime

void factorial()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (i * 1LL * fact[i - 1]) % M;
}

int nCr_fact(int n, int r)
{
    if (r == 0 || r == n)
        return 1;

    int ans = (fact[n] * 1LL * ((binExp(fact[r], M - 2) * 1LL * binExp(fact[n - r], M - 2)) % M)) % M;
    return ans;
}

// Using pascal's triangle:
// TC: O(N^2) precompute, O(1) query
// SC: O(N^2)

void pascal_triangle()
{
    for (int i = 0; i < N_; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                pascal[i][j] = 1;
            else
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % M;
        }
    }
}

int nCr_pascal(int n, int r)
{
    return pascal[n][r];
}

// Using Multiplicative formula:
// for large N, small r
// TC: O(RlogN) query, SC: O(1)
// M must be prime

int nCr(int n, int r)
{
    r = min(r, n - r);

    int ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans = (ans * 1LL * (n - i)) % M;              // n(n-1)(n-2)...(n-r+1)
        ans = (ans * 1LL * binExp(i + 1, M - 2)) % M; // r!
    }
}

// Lucas Theorem: nCr % p = (n%p)C(r%p) * (n/p)C(r/p) % p
// for large N, small prime p

// Hockey Stick Identity: (n+1)C(k+1) = kCk + (k+1)Ck + (k+2)Ck + ... + nCk

// Vandermonde's Identity: (m+n)Ck = mC0*nCk + mC1*nC(k-1) + mC2*nC(k-2) + ... + mCk*nC0
// sum of (nCi)^2 for i=0 to n -> 2nCn

// x1 + x2 + x3 + ... + xn = r
// no. of non-negative integral solutions: (n+r-1)C(r)