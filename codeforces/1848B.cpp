#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int c[n], idx[k + 1], maxdiff[k + 1][2];

        for (int i = 1; i <= k; i++)
        {
            idx[i] = -1;
            maxdiff[i][0] = INT_MIN;
            maxdiff[i][1] = INT_MIN;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> c[i];

            int diff = i - idx[c[i]] - 1;

            if (diff > maxdiff[c[i]][0])
            {
                maxdiff[c[i]][1] = maxdiff[c[i]][0];
                maxdiff[c[i]][0] = diff;
            }
            else if (diff > maxdiff[c[i]][1])
            {
                maxdiff[c[i]][1] = diff;
            }

            idx[c[i]] = i;
        }

        for (int i = 1; i <= k; i++)
        {
            if (maxdiff[i][0] == INT_MIN)
                continue;

            int diff = n - idx[i] - 1;
            if (diff > maxdiff[i][0])
            {
                maxdiff[i][1] = maxdiff[i][0];
                maxdiff[i][0] = diff;
            }
            else if (diff > maxdiff[i][1])
            {
                maxdiff[i][1] = diff;
            }
        }

        int ans = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (maxdiff[i][0] == INT_MIN)
                continue;

            ans = min(ans, max(maxdiff[i][0] / 2, maxdiff[i][1]));
        }

        cout << ans << endl;
    }
}