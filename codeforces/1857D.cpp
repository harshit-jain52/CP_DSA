#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n], b[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int maxdiff = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            maxdiff = max(maxdiff, a[i] - b[i]);
        }

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            if (a[i] - b[i] == maxdiff)
            {
                v.push_back(i + 1);
            }
        }

        cout << v.size() << endl;
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}