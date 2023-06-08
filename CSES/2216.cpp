#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    int a[n], idx[n + 1];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        idx[a[i]] = i;
    }

    ll ct = 1;

    for (i = 2; i <= n; i++)
    {
        if (idx[i] < idx[i - 1])
        {
            ct++;
        }
    }

    cout << ct;
}