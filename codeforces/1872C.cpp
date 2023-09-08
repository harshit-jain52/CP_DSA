#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int l, r;
    cin >> l >> r;

    if (l == r)
    {
        for (int num = 2; num * num <= l; num++)
        {
            if (l % num == 0)
            {
                cout << l / num << " " << l - l / num;
                return;
            }
        }
        cout << -1;
        return;
    }

    int ev = max((l % 2 == 0) ? l : l + 1, (r % 2 == 0) ? r : r - 1);

    if (ev == 2)
    {
        cout << -1;
        return;
    }

    cout << ev / 2 << " " << ev / 2;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}