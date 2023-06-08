#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k;
    string s;
    cin >> t;
    while (t--)
    {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        int i, burls = 0, possible = 0;

        cin >> n >> k;
        cin >> s;

        for (i = 0; i < n; i++)
        {
            if (isupper(s[i]))
            {
                upper[s[i] - 'A']++;
            }
            else
            {
                lower[s[i] - 'a']++;
            }
        }

        for (i = 0; i < 26; i++)
        {
            burls += min(upper[i], lower[i]);
        }

        for (i = 0; i < 26; i++)
        {

            possible += abs(upper[i] - lower[i]) / 2;
        }

        burls += min(k, possible);

        cout << burls << endl;
    }
}