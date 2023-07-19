#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    sort(p, p + n);

    if (n % 2 == 1)
    {
        ll med = p[n / 2];
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(p[i] - med);
        }

        cout << ans;
    }
    else
    {
        ll med1 = p[n / 2], med2 = p[n / 2 - 1];
        ll ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            ans1 += abs(p[i] - med1);
            ans2 += abs(p[i] - med2);
        }

        cout << min(ans1, ans2);
    }
}