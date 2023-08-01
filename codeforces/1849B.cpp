#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if (x.first != y.first)
        return (x.first > y.first);
    else
    {
        return (x.second < y.second);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
        {
            int num = a[i] % k;
            if (num == 0)
                num = k;

            v[i] = {num, i + 1};
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < n; i++)
        {
            cout << v[i].second << " ";
        }
        cout << endl;
    }
}