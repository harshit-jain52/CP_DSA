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
        int n;
        ll m;
        cin >> n >> m;

        if (n > m)
        {
            cout << "NO" << endl;
        }
        else if (n % 2 == 1)
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n - 1; i++)
            {
                cout << 1 << " ";
                m--;
            }
            cout << m << endl;
        }
        else
        {
            if (m % 2 == 0)
            {
                cout << "YES" << endl;
                for (int i = 1; i <= n - 2; i++)
                {
                    cout << 1 << " ";
                    m--;
                }
                cout << m / 2 << " " << m / 2 << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}