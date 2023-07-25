#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<ll, int> nesw, nwse, ns, we;
        ll ct = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;

            ct += 2 * nesw[y - x];
            nesw[y - x]++;

            ct += 2 * nwse[y + x];
            nwse[y + x]++;

            ct += 2 * ns[y];
            ns[y]++;

            ct += 2 * we[x];
            we[x]++;
        }
        cout << ct << endl;
    }
}