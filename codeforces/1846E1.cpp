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
        ll n;
        cin >> n;

        bool isPossible = false;

        for (ll k = 2; k*k < n; k++)
        {
            ll sum = 1 + k + k * k;
            ll tmp = k * k * k;

            while (sum < n)
            {
                sum += tmp;
                tmp *= k;
            }
            if (sum == n)
            {
                isPossible = true;
                break;
            }
        }

        if (isPossible)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}