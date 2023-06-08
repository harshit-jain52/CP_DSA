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
        int n, ctd = 0, ctk = 0;
        cin >> n;
        string s;
        cin >> s;
        map<pair<int, int>, int> m;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
                ctd++;
            else
                ctk++;

            if (ctd == 0)
                cout << ctk << " ";
            else if (ctk == 0)
                cout << ctd << " ";
            else
            {
                int g = __gcd(ctd, ctk);

                cout << ++m[{ctd / g, ctk / g}] << " ";
            }
        }

        cout << endl;
    }
}