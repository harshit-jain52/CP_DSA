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
        char k;
        string s, t;
        cin >> n >> k >> s;

        for (i = 0; i < n; i++)
        {
            if (s[i] < k)
            {
                break;
            }
            t.push_back(s[i]);
        }

        t.push_back(k);

        for (; i < n; i++)
        {
            t.push_back(s[i]);
        }

        cout << t << endl;
    }
}