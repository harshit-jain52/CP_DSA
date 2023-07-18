#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n), v(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    if (n == 1)
        cout << 0 << endl
             << 0;
    else
    {
        v = a;
        sort(v.begin(), v.end());

        int minUpperLimit[n];
        minUpperLimit[n - 1] = v[n - 1].second;
        for (int i = n - 2; i >= 0; i--)
        {
            minUpperLimit[i] = min(minUpperLimit[i + 1], v[i].second);
        }
        map<pair<int, int>, int> to_print1;
        for (int i = 0; i < n - 1; i++)
        {
            to_print1[v[i]] = (v[i].second >= minUpperLimit[i + 1]);
        }
        to_print1[v[n - 1]] = 0;

        int maxUpperLimit[n];
        maxUpperLimit[0] = v[0].second;
        for (int i = 1; i < n; i++)
        {
            maxUpperLimit[i] = max(maxUpperLimit[i - 1], v[i].second);
        }
        map<pair<int, int>, int> to_print2;
        for (int i = n - 1; i > 0; i--)
        {
            to_print2[v[i]] = (v[i].second <= maxUpperLimit[i - 1]);
        }
        to_print2[v[0]] = 0;

        for (int i = 0; i < n; i++)
        {
            cout << to_print1[a[i]] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << to_print2[a[i]] << " ";
        }
    }
}