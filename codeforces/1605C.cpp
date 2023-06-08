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
        int n;
        string s;
        cin >> n;
        cin >> s;
        int i, j, flag = 0, start, minlen = n;
        int ctb[n + 1], ctc[n + 1];
        ctb[0] = ctc[0] = 0;

        for (i = 0; i < n; i++)
        {
            ctb[i + 1] = ctb[i] + (int)(s[i] == 'b');
            ctc[i + 1] = ctc[i] + (int)(s[i] == 'c');
        }

        for (i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                start = i;
                break;
            }
        }

        while (i < n)
        {
            for (j = start + 1; j <= start + 8 && j < n; j++)
            {
                if (s[j] == 'a')
                {
                    int currlen = j - start + 1;
                    int countb = ctb[j+1] - ctb[start+1], countc = ctc[j+1] - ctc[start+1];

                    if (currlen - countb - countc > countb && currlen - countb - countc > countc)
                    {
                        if (currlen <= minlen)
                        {
                            minlen = currlen;
                            flag = 1;
                        }
                    }
                }
            }

            for (i = start + 1; i < n; i++)
            {
                if (s[i] == 'a')
                {
                    start = i;
                    break;
                }
            }
        }

        if (flag)
        {
            cout << minlen;
        }
        else
        {
            cout << -1;
        }

        cout << '\n';
    }
}