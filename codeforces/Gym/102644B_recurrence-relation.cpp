#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

long long binExp(int a, long long b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    /*
    ai = 1*26^(i-1) + 18*(ai-1) + 5*(26^(i-1) - ai-1)
    -> ai = 6*26^(n-1) + 13*(ai-1)
    a1 = 19

    solving the recurrence, we get an = (7/13)13^n + (6/13)26^n
     */

    long long INV = binExp(13, M - 2);
    cout << (((7 * binExp(13, n)) % M * INV) % M + ((6 * binExp(26, n)) % M * INV) % M) % M;
}