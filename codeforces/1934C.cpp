#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
#define X first
#define Y second

void solve()
{
    int n, m;
    cin >> n >> m;
    int d1, d2, d3, d4;

    vector<pair<int, int>> xy(5);
    xy[0] = {1, 1};
    cout << "? " << xy[0].X << " " << xy[0].Y << endl;
    cin >> d1;
    // diagonal: x+y=d1+2

    xy[1].X = min(n, d1 + 1), xy[2].Y = min(m, d1 + 1);
    xy[1].Y = d1 + 2 - xy[1].X, xy[2].X = d1 + 2 - xy[2].Y;

    cout << "? " << xy[1].X << " " << xy[1].Y << endl;
    cin >> d2;
    cout << "? " << xy[2].X << " " << xy[2].Y << endl;
    cin >> d3;

    xy[3].Y = xy[1].Y + d2 / 2, xy[4].X = xy[2].X + d3 / 2;
    xy[3].X = d1 + 2 - xy[3].Y, xy[4].Y = d1 + 2 - xy[4].X;
    cout << "? " << xy[3].X << " " << xy[3].Y << endl;
    cin >> d4;

    if (d1 == 0)
        cout << "! " << 1 << " " << 1 << endl;
    else if (d2 == 0)
        cout << "! " << xy[1].X << " " << xy[1].Y << endl;
    else if (d3 == 0)
        cout << "! " << xy[2].X << " " << xy[2].Y << endl;
    else if (d4 == 0)
        cout << "! " << xy[3].X << " " << xy[3].Y << endl;
    else
        cout << "! " << xy[4].X << " " << xy[4].Y << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}