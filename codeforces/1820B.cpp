#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll consec = 0, maxcon = 0, i, n = s.size();
        for (i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                consec++;
            }
            else
            {
                maxcon = max(maxcon, consec);
                consec = 0;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                consec++;
            }
            else
            {
                break;
            }
        }

        maxcon = max(maxcon, consec);

        if (maxcon >= n)
        {
            cout << n * n << endl;
        }
        else
        {
            if (maxcon == 1 || maxcon == 0)
            {
                cout << maxcon << endl;
            }
            else
            {
                ll ans = 0, num = 2;
                for (i = maxcon - 1; i > 0; i--, num++)
                {
                    ans = max(ans, i * num);
                }
                cout << ans << endl;
            }
        }
    }
}