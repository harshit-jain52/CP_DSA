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
        int n, i;
        cin >> n;
        string s, t, res;
        cin >> s;
        t.push_back(s[0]);

        for (i = 1; i < n; i++)
        {
            if (s[i] < s[i - 1] || (s[i] == s[i - 1] && s[i] < s[0]))
            {
                t.push_back(s[i]);
            }
            else
            {
                break;
            }
        }

        res = t;
        reverse(t.begin(), t.end());
        res += t;
        cout << res << endl;
    }
}