#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int i, left = 0, right = 0, n = s.size(), ct = 0;
    map<int, int> ctfreq;

    for (i = n - 1; i >= 0; i--)
    {
        if (s[i] == ')')
        {
            right++;
        }
        else
        {
            if (right > 0)
            {
                right--;
            }
            else
            {

                s[i] = '*';
            }
        }
    }

    //cout << s << endl;

    for (i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            left++;
        }
        else if (s[i] == ')')
        {
            if (left > 0)
            {
                ct++;
                left--;
            }
            else
            {
                ctfreq[ct]++;
                ct = 0;
            }
        }
        else
        {
            ctfreq[ct]++;
            ct = 0;
        }
    }
    ctfreq[ct]++;

    auto p = *(--ctfreq.end());

    if (p.first > 0)
    {
        cout << 2 * p.first << " " << p.second;
    }
    else
    {
        cout << 0 << " " << 1;
    }
    cout << endl;
}