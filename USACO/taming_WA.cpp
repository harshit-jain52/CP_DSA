#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz(x) (int)(x).size()
typedef long long ll;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=809

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
    setIO("taming");

    int n;
    cin >> n;
    int log[n];
    for (int i = 0; i < n; i++)
    {
        cin >> log[i];
    }

    log[0] = 0;
    for (int i = n - 2; i > 0; i--)
    {
        if (log[i + 1] > 0)
        {
            log[i] = log[i + 1] - 1;
        }
    }

    int maxbreakouts = 0, minbreakouts = 0;
    for (int i = 0; i < n; i++)
    {
        if (log[i] == 0 || log[i] == -1)
            maxbreakouts++;
        if (log[i] == 0)
            minbreakouts++;
    }

    cout << minbreakouts << " " << maxbreakouts << endl;
}