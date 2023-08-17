#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        if (n == 1)
            cout << 0;
        else
        {
            int ct = 0, minel = p[0], minSpecial = 1e7;

            for (int i = 1; i < n; i++)
            {
                if (p[i] > minel && p[i] < minSpecial)
                {
                    ct++;
                    minSpecial = p[i];
                }
                minel = min(minel, p[i]);
            }

            cout << ct;
        }
        cout << endl;
    }
}