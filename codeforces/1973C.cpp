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
    int p[n + 1], q[n + 1];
    vector<pair<int, int>> v1, v2;
    int pos1 = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] == 1)
            pos1 = i;
    }

    for (int i = 1; i <= n; i++)
    {
        if (pos1 & 1)
        {
            if (i % 2 == 0 && i != n)
                v1.push_back({p[i], i});
            else
                v2.push_back({p[i], i});
        }
        else
        {
            if (i % 2 == 1 && i != 1)
                v1.push_back({p[i], i});
            else
                v2.push_back({p[i], i});
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int num = n;
    for (auto it : v1)
    {
        q[it.second] = num--;
    }
    for (auto it : v2)
    {
        q[it.second] = num--;
    }

    for (int i = 1; i <= n; i++)
        cout << q[i] << " ";
    cout << endl;
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