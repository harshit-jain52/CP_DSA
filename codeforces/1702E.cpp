#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;

vector<int> graph[N];
vector<int> group(N);
bool is_bipartite = true;

void dfs(int v, bool color)
{
    group[v] = color;

    for (int child : graph[v])
    {
        if (group[child] != -1)
            is_bipartite &= (group[child] != color);
        else
            dfs(child, !color);
    }
}

void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        graph[i].clear();
        group[i] = -1;
    }
    is_bipartite = true;
}

bool solve()
{
    int n;
    cin >> n;
    reset(n);

    vector<int> ct(n + 1, 0);

    bool isPossible = true;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ct[a]++;
        ct[b]++;
        if (ct[a] > 2 || ct[b] > 2 || a == b)
            isPossible = false;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (!isPossible)
        return false;

    for (int i = 1; i <= n; i++)
    {
        if (group[i] == -1)
            dfs(i, 0);
    }

    return is_bipartite;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}