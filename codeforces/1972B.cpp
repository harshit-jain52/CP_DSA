#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ct = 0;
    for (int i = 0; i < n; i++)
        ct += (s[i] == 'U');

    return (ct % 2);
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}