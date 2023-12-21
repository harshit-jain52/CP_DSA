#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int M = 1e9 + 9;
const int P = 31;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * P) % M;

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = (pref[i] * P + (s[i] - 'a' + 1)) % M;

    function<ll(int, int)> get_hash = [&](int l, int r) -> ll
    {
        ll h = (pref[r + 1] + M - (p_pow[r - l + 1] * pref[l]) % M) % M;
        return h;
    };

    // Periods of String
    for (int i = 1; i <= n; i++)
    {
        int idx = 0;
        bool flag = true;
        while (idx < n)
        {
            int len = min(i, n - idx);
            flag &= (get_hash(0, len - 1) == get_hash(idx, idx + len - 1));
            idx += len;
        }
        if (flag)
            cout << i << " ";
    }
}