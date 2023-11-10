#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int N = 2e5 + 10;

vector<int> graph[N];
vector<int> rev[N];
vector<int> ids(N);
bool vis[N];
vector<int> sc;

int makeValid(int v, int n)
{
    if (v > 0)
        return v;
    else
        return n - v;
}

void kosarajuDFS1(int v)
{
    vis[v] = true;
    for (auto child : graph[v])
    {
        if (!vis[child])
            kosarajuDFS1(child);
    }

    sc.push_back(v);
}

void kosarajuDFS2(int v, int id)
{
    vis[v] = true;
    ids[v] = id;
    for (auto child : rev[v])
    {
        if (!vis[child])
            kosarajuDFS2(child, id);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> m >> n;

    while (m--)
    {
        char a, b;
        int x, y;

        cin >> a >> x >> b >> y;

        if (a == '-')
            x = -x;
        if (b == '-')
            y = -y;

        graph[makeValid(-x, n)].push_back(makeValid(y, n));
        graph[makeValid(-y, n)].push_back(makeValid(x, n));

        rev[makeValid(x, n)].push_back(makeValid(-y, n));
        rev[makeValid(y, n)].push_back(makeValid(-x, n));
    }

    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!vis[i])
            kosarajuDFS1(i);
    }

    memset(vis, false, sizeof(vis));
    int id = 1;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int v = sc[i];
        if (!vis[v])
            kosarajuDFS2(v, id++);
    }

    for (int i = 1; i <= n; i++)
    {
        if (ids[i] == ids[i + n])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ids[i] > ids[i + n])
            cout << "+ ";
        else
            cout << "- ";
    }
}