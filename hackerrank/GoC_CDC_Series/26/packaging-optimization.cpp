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
    int minx = 2000, miny = 2000, maxx = -1, maxy = -1;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '1')
            {
                miny = min(miny, j + 1);
                maxy = max(maxy, j + 1);
                minx = min(minx, i + 1);
                maxx = max(maxx, i + 1);
            }
        }
    }

    cout << minx << " " << miny << " " << maxx << " " << maxy << endl;
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