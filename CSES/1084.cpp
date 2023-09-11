#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;

    ll a[n], b[m];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0;

    int ct = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j] - k)
            i++;

        else if (a[i] > b[j] + k)
            j++;
        else
        {
            ct++;
            i++;
            j++;
        }
    }

    cout << ct << endl;
}