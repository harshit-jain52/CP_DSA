#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    cin >> n >> m;
    ll a[n];
    vector<int> v(n, 0);
    bool dec = false;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 1; i < n - 1; i++)
    {
        if (a[i] < a[i - 1])
        {
            dec = true;
        }
        if (a[i] < a[i + 1] && dec)
        {
            v[i + 1] = 1;
            dec = false;
        }
    }
    vector<int> vsum(n + 1, 0);
    for (i = 0; i < n; i++)
    {
        vsum[i + 1] = vsum[i] + v[i];
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        if (r - l <= 1)
        {
            cout << "Yes";
        }
        else
        {
            if (vsum[r] - vsum[l + 1] == 0)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
        }

        cout << endl;
    }
}