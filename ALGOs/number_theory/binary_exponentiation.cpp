#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
typedef long long ll;

/*
a^b %M
a,b <= 10^9
TC: log(b)
*/

// Recursive Method
int binExpRecur(int a, int b)
{
    if (b == 0)
        return 1;

    int res = binExpRecur(a, b / 2);

    if (b % 2 == 0)
        return (res * 1LL * res) % M;
    else
        return (a * 1LL * ((res * 1LL * res) % M) % M);
}

// Iterative Method [Faster than recursive]
int binExpIter(int a, int b)
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

/*
Handle Large Exponentiation

- if a <= 10^18
    problem: a>M
    solution: (a%=M) then binary exponentiation [a^b % M = (a%M)^b]

- if M <= 10^18
    problem: overflow (even for long long)
    solution: binary multiplication
    TC : logb*logM

- if b <= 10^18
    solution: pass long long b

- if b is given very large (an exponential value p^q)
    e.g. if we are told to calculate a^(p^q) % M
    solution: a^b % M = a^(b%ETF(M)) % M  [Euler's Theorem]
        if M is prime, a^(b%(M-1)) % M

    *ETF = Euler Totient Function
        ETF(N) = no. of positive integers < N coprime with N
         = N * product of all distinct (1-1/p) where p is prime factor of N
        if N is prime, ETF(N) = 1-N (obviously)
*/

ll binMultiply(ll x, ll y)
{
    int ans = 0;
    while (y > 0)
    {
        if (y & 1)
        {
            ans = (ans + x) % M;
        }
        x = (x + x) % M;
        y = y >> 1;
    }
    return ans;
}

ll binExpLarge(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = binMultiply(ans, a);

        a = binMultiply(a, a);
        b = b >> 1;
    }
    return ans;
}