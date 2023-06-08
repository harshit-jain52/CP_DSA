#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll r, g, b;
    cin >> r >> g >> b;

    ll count = r / 3 + g / 3 + b / 3 + min(r % 3, min(g % 3, b % 3));

    if (r != 0 && g != 0 && b != 0)
    {
        if (r % 3 + g % 3 + b % 3 == 4 && min(r % 3, min(g % 3, b % 3)) == 0)
        {
            count++;
        }
    }

    cout << count;
}