#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, diff;
    cin >> n;
    string s;
    int a[n], b[n];
    cin >> s;

    for (i = 0; i < n; i++)
    {
        a[i] = s[i];
        b[i] = s[i + n];
    }

    sort(a, a + n);
    sort(b, b + n);

    diff = a[0] - b[0];

    for (i = 0; i < n; i++)
    {
        if (diff * (a[i] - b[i]) <= 0)
        {
            break;
        }
    }

    if (i == n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}