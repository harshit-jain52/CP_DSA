#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll x;
    cin >> x;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int i = 0, j = n - 1;
    int ct = 0;
    while (i < j)
    {
        if (a[i] + a[j] <= x)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }
        ct++;
    }
    if (i == j)
        ct++;

    cout << ct << endl;
}