#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ull c, s[n], ans;
        cin >> c;

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        ull lo = 1, hi = 1e9, mid;

        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            ull sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += (s[i] + 2 * mid) * (s[i] + 2 * mid);
                if (sum > c)
                    break;
            }

            if (sum == c)
            {
                ans = mid;
                break;
            }

            else if (sum > c)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        cout << ans << endl;
    }
}