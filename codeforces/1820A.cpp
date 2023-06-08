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
        int ct = 0, i, n = s.size();

        if (n == 1)
        {
            if (s[0] == '^')
            {
                cout << 1;
            }
            else
            {
                cout << 2;
            }
        }
        else
        {
            int consec = 0;
            for (i = 0; i < n; i++)
            {
                if (s[i] == '_')
                {
                    consec++;
                }
                else if (consec > 0)
                {
                    ct += consec - 1;
                    consec = 0;
                }
            }

            if (s[0] != '^')
            {
                ct++;
            }
            if (s[n - 1] != '^')
            {
                ct += consec;
            }
            cout << ct;
        }
        cout << endl;
    }
}