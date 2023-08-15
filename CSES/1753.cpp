#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> prefix_function(string s)
{
    int n = s.length();
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
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();

    string str = p + '#' + s;

    vector<int> v = prefix_function(str);

    ll ct = 0;

    for (int i = m + 1; i <= n + m; i++)
    {
        if (v[i] == m)
            ct++;
    }

    cout << ct;
}