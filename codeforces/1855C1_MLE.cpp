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
        int a[n], maxelem = -30, idx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > maxelem)
            {
                maxelem = a[i];
                idx = i;
            }
        }

        vector<pair<int, int>> op;
        for (int i = 1; i < n; i++)
        {
            while (a[i] < a[i - 1])
            {
                a[i] += maxelem;
                op.push_back({i + 1, idx + 1});
                if (a[i] > maxelem)
                {
                    maxelem = a[i];
                    idx = i;
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