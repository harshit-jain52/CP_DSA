#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char chr(int x)
{
    return '0' + x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string a, s, ans;
        cin >> a >> s;
        int i = a.size() - 1, j = s.size() - 1;

        while (j >= 0)
        {
            if (i < 0)
            {
                ans.push_back(s[j]);
                j--;
            }
            else
            {
                if (s[j] >= a[i])
                {
                    ans.push_back(chr(s[j] - a[i]));
                    i--;
                    j--;
                }
                else
                {
                    if (j == 0)
                    {
                        break;
                    }
                    else if (s[j - 1] != '1')
                    {
                        break;
                    }
                    else
                    {
                        ans.push_back(chr(10 + (int)(s[j] - a[i])));
                        j -= 2;
                        i--;
                    }
                }
            }
        }

        if (j >= 0 || i >= 0)
        {
            cout << -1;
        }
        else
        {
            reverse(ans.begin(), ans.end());

            for (i = 0; ans[i] == '0'; i++)
                ;

            for (; i < ans.size(); i++)
            {
                cout << ans[i];
            }
        }
        cout << endl;
    }
}