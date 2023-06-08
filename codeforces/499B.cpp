#include <bits/stdc++.h>
using namespace std;

string minLength(string s1, string s2)
{
    if (s1.size() <= s2.size())
    {
        return s1;
    }
    else
    {
        return s2;
    }
}

int main()
{
    int n, m, i;
    cin >> n >> m;

    unordered_map<string, string> s;
    string a, b, c;

    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        s[a] = b;
    }

    vector<string> v;
    for (i = 0; i < n; i++)
    {
        cin >> c;
        v.push_back(c);
    }

    for (i = 0; i < n; i++)
    {
        cout << minLength(v[i], s[v[i]]) << " ";
    }
}