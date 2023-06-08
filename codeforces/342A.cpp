#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    atmost 7
    only possible triplets:
    1 2 4
    1 2 6
    1 3 6
    */

    int n;
    cin >> n;
    int a[n], i;
    unordered_map<int, int> m;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    if (m[1] != n / 3 || m[5] > 0 || m[7] > 0 || m[2] + m[3] != n / 3 || m[4] + m[6] != n / 3 || m[2] < m[4] || m[2] + m[3] < m[6])
    {
        cout << -1;
    }
    else
    {
        for (i = 0; i < m[4]; i++)
        {
            cout << "1 2 4" << endl;
            m[2]--;
        }
        for (i = 0; i < m[2]; i++)
        {
            cout << "1 2 6" << endl;
            m[6]--;
        }
        for (i = 0; i < m[6]; i++)
        {
            cout << "1 3 6" << endl;
        }
    }
}