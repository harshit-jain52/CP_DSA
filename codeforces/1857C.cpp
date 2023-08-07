#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int func(int k)
{
    for (int i = 1; i < k; i++)
    {
        if (i * (i - 1) / 2 == k)
            return i;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = n * (n - 1) / 2;
        map<int, int> ct;
        vector<int> v;

        int a[m];
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            ct[a[i]]++;
        }

        sort(a, a + m);

        // for (int i = 0; i < m; i++)
        // {
        //     cout << a[i] << " ";
        // }

        for (int i = m - 1; i >= 0; i--)
        {
            if (ct[a[i]] == -1)
                continue;

            int c = 0;
            if (a[i] == a[m - 1])
            {
                c = func(ct[a[i]]);
            }
            else
            {
                int t = 1;
                while (ct[a[i]] > t * v.size() + t * (t - 1) / 2)
                {
                    t++;
                }
                c = t;
            }
            ct[a[i]] = -1;

            for (int j = 0; j < c; j++)
            {
                v.push_back(a[i]);
            }
        }

        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}