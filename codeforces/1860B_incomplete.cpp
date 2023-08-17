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
        ll m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;

        if (ak * k >= m)
        {
            m = m % k;
            if (a1 >= m)
                cout << 0;
            else
                cout << (m - a1);
        }
        else
        {
            m = m - ak * k;
            if (a1 >= m)
            {
                cout << 0;
            }
            else
            {
                int ct=m/k;
                

            }
        }

        cout << endl;
    }
}