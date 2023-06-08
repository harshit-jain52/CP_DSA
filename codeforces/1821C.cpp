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
        vector<bool> alph(26, 0);
        vector<int> maxgaps;
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            alph[s[i] - 'a'] = true;
        }

        for (int i = 0; i < 26; i++)
        {
            if (alph[i])
            {
                int ct = 0;
                int maxct = 0;

                for (int j = 0; j < s.size(); j++)
                {
                    if (s[j] == 'a' + i)
                    {
                        maxct = max(maxct, ct);
                        ct = 0;
                    }
                    else
                    {
                        ct++;
                    }
                }
                maxct = max(maxct, ct);

                maxgaps.push_back(maxct);
            }
        }

        int minmax = *min_element(maxgaps.begin(), maxgaps.end());

        if (minmax == 0)
        {
            cout << 0;
        }
        else
        {
            int num;
            for (num = 0;; num++)
            {
                if (minmax < (1 << num))
                {
                    break;
                }
            }
            cout << num;
        }
        cout << endl;
    }
}