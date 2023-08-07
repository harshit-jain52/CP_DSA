#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<ll, int> ct;
        ll x[n], tmp[n];

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            tmp[i] = x[i];
            ct[x[i]]++;
        }

        int prev = 0;
        sort(tmp, tmp + n);

        ll leftprefix[n + 1], rightprefix[n + 1];
        leftprefix[0] = rightprefix[n] = 0;

        for (int i = 0; i < n; i++)
        {
            leftprefix[i + 1] = leftprefix[i] + tmp[i];
            rightprefix[n - 1 - i] = rightprefix[n - i] + tmp[n - i - 1];
        }

        map<ll, ll> m;
        for (int i = 0; i < n; i++)
        {
            ll l = i * tmp[i] - leftprefix[i] + i;
            ll r = rightprefix[i + 1] - (n - 1 - i) * tmp[i] + (n - 1 - i);
            m[tmp[i]] = l + r + 1;
        }

        for (int i = 0; i < n; i++)
        {
            cout << m[x[i]] << " ";
        }

        cout << endl;
    }
}