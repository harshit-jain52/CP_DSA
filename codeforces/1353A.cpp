#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    long long int n, m;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;

        if (n == 1)
        {
            cout << 0 << endl;
        }
        else if (n == 2)
        {
            cout << m << endl;
        }
        else
        {
            cout << 2 * m << endl;
        }
    }

    return 0;
}