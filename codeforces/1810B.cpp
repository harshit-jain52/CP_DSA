#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void printSteps(ll n)
{
    if (n == 1)
    {
        return;
    }
    int b = n & (2);
    printSteps(n >> 1);

    if (b)
    {
        cout << 2 << " ";
    }
    else
    {
        cout << 1 << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        if (n & 1)
        {
            for (ll i = 1; i <= 40; i++)
            {
                if (n < (1 << i))
                {
                    cout << i - 1 << endl;
                    break;
                }
            }

            printSteps(n);
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
}