#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        map<int, int> idxb, closest;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            idxb[b[i]] = i;
        }
        closest[2 * n - 1] = idxb[2 * n];
        for (int i = 2 * n - 3; i >= 1; i--)
        {
            closest[i] = min(closest[i + 2], idxb[i + 1]);
        }

        int swaps = 2 * n + 1;

        for (int i = 0; i < n; i++)
        {
            swaps = min(swaps, i + closest[a[i]]);
        }

        cout << swaps << endl;
    }
}