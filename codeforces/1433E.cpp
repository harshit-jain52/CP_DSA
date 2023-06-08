#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    nC(n/2) * (n/2-1)! * (n/2-1)! / 2
    (n!/(n/2)^2)/2
*/

ll fact[21];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        fact[i] = i * fact[i - 1];
    }

    ll n;
    cin >> n;

    ll ans = (fact[n] / ((n * n) / 4)) / 2;

    cout << ans;
}