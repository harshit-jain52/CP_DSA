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
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();

        string str = b + '#' + a;

        vector<int> v = prefix_function(str);

        vector<int> ans;

        for (int i = m + 1; i <= n + m; i++)
        {
            if (v[i] == m)
                ans.push_back(i - 2 * m + 1);
        }

        if (ans.size() == 0)
        {
            cout << "Not Found";
        }
        else
        {
            cout << ans.size() << endl;
            for (auto it : ans)
            {
                cout << it << " ";
            }
        }

        cout << endl;
    }
}