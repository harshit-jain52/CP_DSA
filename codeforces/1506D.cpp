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
        int n, i;
        cin >> n;
        unordered_map<ll, int> m;
        for (i = 0; i < n; i++)
        {
            ll tmp;
            cin >> tmp;
            m[tmp]++;
        }
        int maxct = 0;
        for (auto it : m)
        {
            maxct = max(maxct, it.second);
        }

        if (2 * maxct > n)
        {
            cout << 2 * maxct - n;
        }
        else
        {
            if (n % 2 == 0)
                cout << 0;
            else
                cout << 1;
        }
        cout << endl;
    }
}