#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, minlength, i, j;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> n >> s;
        minlength = n;

        for (i = 0, j = n - 1; i < j;)
        {
            if (s[i] == s[j])
            {
                break;
            }

            minlength -= 2;
            i++;
            j--;
        }

        cout << minlength << endl;
    }
}