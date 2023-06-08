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

        int ct = (s.size() - 1) * 9;
        ct += (s[0] - '0') - 1;
        int i;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] < s[0])
            {
                break;
            }
            if (s[i] > s[0])
            {
                ct++;
                break;
            }
        }
        if (i == s.size())
        {
            ct++;
        }

        cout << ct << endl;
    }
}