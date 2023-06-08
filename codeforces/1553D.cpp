#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--)
    {
        string s, t;
        cin >> s >> t;
        int i = s.size() - 1, j = t.size() - 1;

        while (i >= 0 && j >= 0)
        {
            if (s[i] == t[j])
            {
                i--;
                j--;
            }
            else
            {
                i -= 2;
            }
        }

        if (j >= 0)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        cout << endl;
    }
}