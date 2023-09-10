#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz(x) (int)(x).size()
typedef long long ll;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=832

int n, m, k;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);

    if (sz(name))
    {

        freopen((name + ".in").c_str(), "r", stdin);

        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool check(vector<int> &h, vector<int> order)
{
    vector<int> pos(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        if (order[i] != -1)
            pos[order[i]] = i;
    }

    int h_idx = 0;
    for (int i = 0; i < n && h_idx < m; i++)
    {
        if (pos[h[h_idx]] != -1)
        {
            if (i > pos[h[h_idx]])
                return false;

            i = pos[h[h_idx]];
            h_idx++;
        }
        else
        {
            while (i < n && order[i] != -1)
                i++;

            if (i == n)
                return false;

            order[i] = h[h_idx];
            pos[h[h_idx]] = i;
            h_idx++;
        }
    }

    return true;
}

int main()
{
    setIO("milkorder");
    cin >> n >> m >> k;

    vector<int> hierarchy(m);
    for (int i = 0; i < m; i++)
    {
        cin >> hierarchy[i];
    }

    vector<int> order(n, -1);

    for (int i = 0; i < k; i++)
    {
        int c, p;
        cin >> c >> p;
        order[--p] = c;
    }

    for (int i = 0; i < n; i++)
    {
        if (order[i] == 1)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (order[i] == -1)
        {
            order[i] = 1;

            if (check(hierarchy, order))
            {
                cout << i + 1 << endl;
                return 0;
            }
            order[i] = -1;
        }
    }
}