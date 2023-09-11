#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
#define sz(x) (int)(x).size()
const int M = 1e9 + 7;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=1012

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
    setIO("breedflip");

    int n;
    cin >> n;
    int a1[n], a2[n], a3[n];

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == 'G')
            a1[i] = 1;
        else
            a1[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == 'G')
            a2[i] = 1;
        else
            a2[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        a3[i] = a1[i] + a2[i];
    }

    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (a3[i] == 0)
        {
            ct++;
            for (int j = i; j < n; j++)
            {
                if (a3[j] != 0)
                {
                    i = j;
                    break;
                }
            }
        }
    }

    cout << ct << endl;
}