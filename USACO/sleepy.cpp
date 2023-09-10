#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz(x) (int)(x).size()
typedef long long ll;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=892

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
    setIO("sleepy");
    int n;
    cin >> n;

    int a[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
            ans = i;
    }

    cout << ans << endl;
}