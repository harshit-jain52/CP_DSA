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
        int n, ct, i;
        cin >> n;
        string s;
        cin >> s;

        ct = 0;
        for (i = 1; i < n - 1; i++)
        {
            if (s[i - 1] == s[i + 1])
            {
                ct++;
            }
        }

        cout << (n - 1 - ct) << endl;
    }
}