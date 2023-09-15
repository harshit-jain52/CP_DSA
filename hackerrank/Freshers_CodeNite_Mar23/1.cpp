#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count = 0, i;
        string s;
        cin >> n;
        cin >> s;

        for (i = 0; i < n - 2;)
        {
            if (s[i] == 'k' && s[i + 1] == 'g' && s[i + 2] == 'p')
            {
                count++;
                i += 3;
            }
            else
            {
                i++;
            }
        }

        cout << (n + count * (9 - 3)) << endl;
    }
}