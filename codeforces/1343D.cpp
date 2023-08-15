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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> numOfPairs01(2 * k + 2, 0); // at index i, number of pairs that require 0 or 1 change to sum up to i
        vector<int> numOfPairs0(2 * k + 2, 0);

        for (int i = 0; i < n / 2; i++)
        {
            int l = min(a[i], a[n - 1 - i]);
            int r = max(a[i], a[n - 1 - i]);

            // for 0 or 1 change, sum can be from l+1 to r+k

            numOfPairs01[l + 1]++;
            numOfPairs01[r + k + 1]--;

            numOfPairs0[l + r]++;
        }

        for (int i = 1; i <= 2 * k; i++)
        {
            numOfPairs01[i] += numOfPairs01[i - 1];
        }

        int ans = n;

        for (int i = 1; i <= 2 * k; i++)
        {
            int ct0 = numOfPairs0[i];
            int ct1 = numOfPairs01[i] - ct0;
            int ct2 = n / 2 - (ct0 + ct1);

            ans = min(ans, ct1 + 2 * ct2);
        }

        cout << ans << endl;
    }
}