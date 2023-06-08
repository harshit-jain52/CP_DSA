#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, i, idx;
        cin >> n;
        string s, t;
        char c;
        cin >> s;
        idx = 0;
        c = s[0];

        for (i = 0; i < s.size(); i++)
        {
            if (s[i] <= c)
            {
                c = s[i];
                idx = i;
            }
        }
        t.push_back(s[idx]);
        for (i = 0; i < n; i++)
        {
            if (i == idx)
            {
                continue;
            }
            t.push_back(s[i]);
        }

        cout << t << endl;
    }
}