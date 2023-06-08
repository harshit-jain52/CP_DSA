#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n][m], num = 1;
        if (n == 4)
        {
            for (int j = 0; j < m; j += 2)
            {
                for (int i = 0; i < n; i++)
                {
                    a[i][j] = num;
                    num++;
                }
            }
            for (int j = 1; j < m; j += 2)
            {
                for (int i = 0; i < n; i++)
                {
                    a[i][j] = num;
                    num++;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i += 2)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i][j] = num;
                    num++;
                }
            }

            for (int i = 1; i < n; i += 2)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i][j] = num;
                    num++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}