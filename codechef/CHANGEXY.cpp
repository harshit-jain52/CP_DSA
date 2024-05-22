#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;

    int moves = 0;
    while (b != a)
    {
        if (b % k == 0)
        {
            if (b / k >= a)
            {
                moves++;
                b /= k;
            }
            else
            {
                moves += (b - a);
                b = a;
            }
        }
        else
        {
            int tmp = min(b % k, b - a);
            moves += tmp;
            b -= tmp;
        }
    }
    cout << moves << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}