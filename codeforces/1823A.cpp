#include <bits/stdc++.h>
using namespace std;

int nC2[101];

int main()
{
    for (int i = 0; i <= 100; i++)
    {
        nC2[i] = i * (i - 1) / 2;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int flag = 0, ct;
        for (int i = 0; i <= n; i++)
        {
            if (nC2[i] + nC2[n - i] == k)
            {
                flag = 1;
                ct = i;
                break;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
            for (int i = 0; i < ct; i++)
            {
                cout << -1 << " ";
            }
            for (int i = 0; i < n - ct; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}