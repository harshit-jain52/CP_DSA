#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> z_function(string &s)
{
    int n = s.length();
    vector<int> z(n, 0);

    int l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

vector<int> prefix_function(string &s)
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
    string str;
    cin >> str;

    vector<int> v1 = z_function(str);
    vector<int> v2 = prefix_function(str);

    for (auto it : v1)
        cout << it << " ";

    cout << endl;

    for (auto it : v2)
        cout << it << " ";
}