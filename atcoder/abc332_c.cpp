#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool check(int x, int m, int n, string &s)
{
    int plain = m, logo = x;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            plain = m;
            logo = x;
        }
        else if (s[i] == '2')
        {
            if (logo > 0)
                logo--;
            else
                return false;
        }
        else if (s[i] == '1')
        {
            if (plain > 0)
                plain--;
            else if (logo > 0)
                logo--;
            else
                return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> n >> m;
    string s;
    cin >> s;

    int lo = 0, hi = n, mid;

    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        if (check(mid, m, n, s))
            hi = mid;
        else
            lo = mid + 1;
    }

    if (check(lo, m, n, s))
        cout << lo;
    else
        cout << hi;
}