#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int e[n + 1];
        for (i = 0; i < n; i++)
        {
            cin >> e[i];
        }
        e[n] = 0;
        sort(e, e + n);
        int ct = 0, size = 0;

        for (i = 0; i < n; i++)
        {
            size++;
            if (size >= e[i])
            {
                ct++;
                size = 0;
            }
        }
        cout << ct << endl;
    }
}