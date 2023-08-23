#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll fib[48];
void calculateFib()
{
    fib[0] = 1;
    fib[1] = 1;

    for (int i = 2; i < 48; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

bool solve(ll x, ll y, int n)
{
    if (n == 1)
        return true;

    y = min(y, fib[n + 1] - y + 1);

    if (y > fib[n - 1])
        return false;

    return solve(y, x, n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    calculateFib();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll x, y;
        cin >> x >> y;

        if (solve(x, y, n))
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}