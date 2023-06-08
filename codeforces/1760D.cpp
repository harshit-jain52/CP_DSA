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
        ll a[n];

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<ll> v;
        v.push_back(a[0]);

        for (i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
            {
                v.push_back(a[i]);
            }
        }

        int ct = 0;
        if (v.size() == 1)
        {
            cout << "YES";
        }
        else
        {
            for (i = 0; i < v.size(); i++)
            {
                if (i != 0 && i != v.size() - 1)
                {
                    if (v[i] < v[i - 1] && v[i] < v[i + 1])
                    {
                        ct++;
                    }
                }
                else if (i == 0)
                {
                    if (v[i] < v[i + 1])
                    {
                        ct++;
                    }
                }
                else
                {
                    if (v[i] < v[i - 1])
                    {
                        ct++;
                    }
                }
            }

            if (ct == 1)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
        }

        cout << endl;
    }
}