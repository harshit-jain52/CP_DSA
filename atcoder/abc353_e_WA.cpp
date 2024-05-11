#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int P = 31;
const int N = 3e5 + 10;

int main()
{
    FASTIO
    vector<ll> p_pow(N);
    p_pow[0] = 1;
    for (int i = 1; i < N; i++)
        p_pow[i] = (p_pow[i - 1] * P) % M;

    map<ll, ll> ct;
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int len = s[i].size();
        vector<ll> pref(len + 1, 0);
        for (int j = 0; j < len; j++)
        {
            pref[j + 1] = (pref[j] * P + (s[i][j] - 'a' + 1)) % M;
            ct[pref[j + 1]]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll curr = 0;
        int len = s[i].size();
        vector<ll> pref(len + 1, 0);
        for (int j = 0; j < len; j++)
        {
            pref[j + 1] = (pref[j] * P + (s[i][j] - 'a' + 1)) % M;
            ct[pref[j + 1]]--;
        }

        for (int j = len; j >= 1; j--)
        {
            ans += j * (ct[pref[j]] - curr);
            curr += (ct[pref[j]] - curr);
        }
    }

    cout << ans;
}