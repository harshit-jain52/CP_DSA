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
        int n, i, leftocc, rightocc;
        cin >> n;
        ll a[n], initmex;
        unordered_set<ll> s;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }

        for (initmex = 0; initmex < n; initmex++)
        {
            if (s.find(initmex) == s.end())
            {
                break;
            }
        }

        for (i = 0; i < n; i++)
        {
            if (a[i] == initmex + 1)
            {
                leftocc = i;
                break;
            }
        }
        if (i == n)
        {
            sort(a, a + n);
            int flag = 0;
            for (i = 1; i < n; i++)
            {
                if (a[i] == a[i - 1] || a[i] > initmex)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
        }
        else
        {
            for (i = n - 1; i >= 0; i--)
            {
                if (a[i] == initmex + 1)
                {
                    rightocc = i;
                    break;
                }
            }
            unordered_set<ll> s1;
            ll initmex1;
            for (i = 0; i < n; i++)
            {
                if (i >= leftocc && i <= rightocc)
                {
                    continue;
                }
                s1.insert(a[i]);
            }
            for (initmex1 = 0; initmex1 < n; initmex1++)
            {
                if (s1.find(initmex1) == s.end())
                {
                    break;
                }
            }

            if (initmex == initmex1)
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