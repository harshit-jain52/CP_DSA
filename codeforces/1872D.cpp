#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;

        cin >> n >> x >> y;

        ll numx = n / x;
        ll numy = n / y;
        ll numxy = n / ((x * y) / __gcd(x, y));

        numx -= numxy;
        numy -= numxy;

        ll pos = n * (n + 1) / 2 - (n - numx) * (n - numx + 1) / 2;
        ll neg = numy * (numy + 1) / 2;

        cout << pos - neg << endl;
    }
}