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

        if (n == 1)
        {
            int tmp;
            cin >> tmp;
            cout << "NO";
        }
        else
        {
            ll a[n], sum = 0, ct1 = 0;

            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
                sum += a[i];
                if (a[i] == 1)
                    ct1++;
            }

            if (ct1 * 2 >= sum)
                cout << "NO";
            else
                cout << "YES";
        }
        cout << endl;
    }
}