#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
vector<int> t[N];
vector<int> c(N);
vector<vector<int>> paths;
int m, ct = 0;

void dfs(int vertex, int parent, int consec, int maxconsec)
{
    if (c[vertex] == 1)
    {
        consec++;
        if (consec > maxconsec)
        {
            maxconsec = consec;
        }
    }
    else
    {
        consec = 0;
    }
    
    if (t[vertex].size() == 1 && vertex != 1)
    {
        if (maxconsec <= m)
        {
            ct++;
        }
    }

    for (int child : t[vertex])
    {
        if (child == parent)
            continue;

        dfs(child, vertex, consec, maxconsec);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, n1, n2;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        cin >> n1 >> n2;
        t[n1].push_back(n2);
        t[n2].push_back(n1);
    }
    dfs(1, 0, 0, 0);

    cout << ct;
}