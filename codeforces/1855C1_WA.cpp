#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], maxelem = -30, minelem = 30, idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > maxelem)
            {
                maxelem = a[i];
                idx1 = i;
            }
            if (a[i] < minelem)
            {
                minelem = a[i];
                idx2 = i;
            }
        }

        vector<pair<int, int>> op;

        if (maxelem > 0)
        {
            for (int i = 1; i < n; i++)
            {
                while (a[i] < a[i - 1])
                {

                    a[i] += maxelem;
                    op.push_back({i + 1, idx1 + 1});
                    if (a[i] > maxelem)
                    {
                        maxelem = a[i];
                        idx1 = i;
                    }
                }
            }
        }
        else
        {
            for (int i = n - 2; i >= 0; i--)
            {
                while (a[i] > a[i + 1])
                {
                    a[i] += minelem;
                    op.push_back({i + 1, idx2 + 1});
                    if (a[i] < minelem)
                    {
                        minelem = a[i];
                        idx2 = i;
                    }
                }
            }
        }

        cout << op.size() << endl;
        for (auto it : op)
        {
            cout << it.first << " " << it.second << endl;
        }
        op.clear();
    }
}