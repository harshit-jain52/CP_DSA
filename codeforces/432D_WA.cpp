#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int M = 1e9 + 9;
const int p = 31;

vector<int> presuf(string &s, int n) // string hashing
{
    vector<int> ans;

    vector<ll> p_pow(n);
    p_pow[0] = 1;

    for (int i = 1; i < n; i++)
    {
        p_pow[i] = (p_pow[i - 1] * p) % M;
    }

    vector<ll> h(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + (s[i] - 'A' + 1) * p_pow[i]) % M;
    }

    for (int i = 1; i <= n; i++)
    {
        ll pre_h = h[i];
        ll suff_h = (h[n] + M - h[n - i]) % M;
        if ((pre_h * p_pow[n - i]) % M == suff_h)
            ans.push_back(i);
    }

    return ans;
}

vector<int> kmp(string s, int n) // prefix function
{
    vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int l = pi[i - 1];

        while (l > 0 && s[i] != s[l])
            l = pi[l - 1];

        if (s[i] == s[l])
            l++;

        pi[i] = l;
    }

    return pi;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<int> v = kmp(s, n);

    map<int, int> ct;
    for (int i = 0; i < n; i++)
    {
        ct[v[i]]++;
    }

    vector<int> tolook = presuf(s, n);

    vector<pair<int, int>> to_print;
    for (auto it : tolook)
    {
        to_print.push_back(make_pair(it, ct[it]));
    }

    int pr = to_print.size();
    to_print[pr - 1].second = 1;
    for (int i = pr - 2; i >= 0; i--)
    {
        to_print[i].second += to_print[i + 1].second;
    }

    cout << to_print.size() << endl;
    for (auto it : to_print)
    {
        cout << it.first << " " << it.second << endl;
    }
}