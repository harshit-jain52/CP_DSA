#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz(x) (int)(x).size()
typedef long long ll;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=915

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);

    if (sz(name))
    {

        freopen((name + ".in").c_str(), "r", stdin);

        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("herding");

    int loc[3];
    cin >> loc[0] >> loc[1] >> loc[2];
    sort(loc, loc + 3);

    int diff1 = loc[1] - loc[0] - 1;
    int diff2 = loc[2] - loc[1] - 1;

    int maxd = max(diff1, diff2), mind = min(diff1, diff2);

    if (mind == 0)
        cout << min(2, maxd) << endl
             << maxd << endl;
    else
        cout << min(2, mind) << endl
             << maxd << endl;
}