#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;

        ll ct = 0;

        for (ll pow = 1; pow < 1e10; pow *= 10)
        {
            ct += r / pow - l / pow;
        }
        cout << ct << endl;
    }
}