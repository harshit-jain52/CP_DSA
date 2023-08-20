#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int M = 1e9 + 9;
const int p = 31;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    vector<ll> p_pow(n);
    p_pow[0] = 1;

    for (int i = 1; i < n; i++)
    {
        p_pow[i] = (p_pow[i - 1] * p) % M;
    }

    vector<ll> h(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % M;
    }

    for (int i = 1; i <= n; i++)
    {
        ll pre_h = h[i];
        ll suff_h = (h[n] + M - h[n - i]) % M;
        if ((pre_h * p_pow[n - i]) % M == suff_h)
            if (i != n)
                cout << i << " ";
    }
}