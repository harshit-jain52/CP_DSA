#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>

// Compute x,y such that ax+by=gcd(a,b)

array<ll, 3> eeIter(ll a, ll b)
{
    // (1 * a) + (0 * b) = a and (0 * a) + (1 * b) = b
    array<ll, 3> x = {1, 0, a};
    array<ll, 3> y = {0, 1, b};

    // run extended Euclidean algo
    while (y[2] > 0)
    {
        // keep subtracting multiple of one equation from the other
        ll k = x[2] / y[2];

        for (int i = 0; i < 3; i++)
            x[i] -= k * y[i];

        swap(x, y);
    }

    return x; // x[0] * a + x[1] * b = x[2], x[2] = gcd(a, b)
}

pll eeRecur(ll a, ll b)
{
    if (b == 0)
        return make_pair(1, 0);

    ll x, y;
    tie(y, x) = eeRecur(b, a % b);
    y -= a / b * x;

    return make_pair(x, y);
}