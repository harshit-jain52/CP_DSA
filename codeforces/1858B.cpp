#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, d;
        cin >> n >> m >> d;

        vector<int> s(m);
        for (int i = 0; i < m; i++)
        {
            cin >> s[i];
        }

        s.insert(s.begin(), 1);
        s.push_back(n);

        ll initialCookies = 1;
        for (int i = 1; i <= m + 1; i++)
        {
            int diff = s[i] - s[i - 1];
            initialCookies += diff / d + (int)((i != (m + 1)) && diff % d != 0);
        }

        ll minCookies = INT_MAX;
        int ct = 1;
        for (int i = 1; i <= m; i++)
        {
            int diff1 = s[i] - s[i - 1];
            int diff2 = s[i + 1] - s[i];
            int diff = s[i + 1] - s[i - 1];

            ll cookies = initialCookies - (diff1 / d + (int)(diff1 % d != 0)) - (diff2 / d + (int)(i != m && diff2 % d != 0)) + (diff / d + (int)(i != m && diff % d != 0));

            if (cookies == minCookies)
            {
                ct++;
            }
            if (cookies < minCookies)
            {
                minCookies = cookies;
                ct = 1;
            }
        }

        cout << minCookies << " " << ct << endl;
    }
}