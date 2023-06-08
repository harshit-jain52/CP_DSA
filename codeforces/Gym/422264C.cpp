#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << (int)(1e9);
    }
    else
    {
        ll leftgcd[n + 1], rightgcd[n + 1], remgcd[n];
        leftgcd[0] = rightgcd[n] = 0;

        for (i = 0; i < n; i++)
        {
            leftgcd[i + 1] = __gcd(a[i], leftgcd[i]);
            rightgcd[n - i - 1] = __gcd(a[n - 1 - i], rightgcd[n - i]);
        }

        for (i = 0; i < n; i++)
        {
            remgcd[i] = __gcd(leftgcd[i], rightgcd[i + 1]);
        }

        cout << *max_element(remgcd, remgcd + n);
    }
}