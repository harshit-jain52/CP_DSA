#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    ll ct = 0;
    int last = 0, curr = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            curr++;
            if (curr <= last)
                ct++;
        }
        else
        {
            last = curr;
            curr = 1;
            ct++;
        }
    }

    cout << ct << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}