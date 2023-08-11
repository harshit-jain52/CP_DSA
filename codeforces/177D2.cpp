#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    int a[n], b[m];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<int> toAdd(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        toAdd[i] += b[i];
        toAdd[n - m + 1 + i] -= b[i];
    }

    for (int i = 1; i < n; i++)
    {
        toAdd[i] += toAdd[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << (a[i] + toAdd[i]) % c << " ";
    }
}