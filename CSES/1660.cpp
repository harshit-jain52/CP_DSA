#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    ll x;
    cin >> n >> x;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i = 0, j = 0;

    ll sum = a[i];
    int ct = 0;
    while (j < n)
    {
        while (i <= j && sum > x)
        {
            sum -= a[i];
            i++;
        }

        if (sum == x)
            ct++;

        j++;
        if (j < n)
            sum += a[j];
    }

    cout << ct;
}