#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int left[n], right[n];
    left[0] = (s[0] != '>');
    right[n - 1] = (s[n - 1] != '<');

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '>')
            left[i] = 0;
        else
            left[i] = left[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '<')
            right[i] = 0;
        else
            right[i] = right[i + 1] + 1;
    }

    int maxlen = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int l = i, r = i + 1;
        maxlen = max(maxlen, 2 * min(left[l], right[r]));
    }
    cout << maxlen << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}