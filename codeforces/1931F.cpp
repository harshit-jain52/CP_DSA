#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> g[N];
vector<bool> visited(N);
vector<bool> recur_stack(N);

bool detectCycle(int vertex)
{
    recur_stack[vertex] = true;
    visited[vertex] = true;
    bool ans = false;

    for (auto child : g[vertex])
    {
        if (recur_stack[child])
        {
            ans = true;
            break;
        }
        if (visited[child])
            continue;

        ans |= detectCycle(child);
    }

    recur_stack[vertex] = false;
    return ans;
}

bool isCycle(int n)
{
    bool final = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            final |= detectCycle(i);
    }

    return final;
}

void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        visited[i] = false;
        recur_stack[i] = false;
    }
}

bool solve()
{
    int n, k;
    cin >> n >> k;
    reset(n);
    while (k--)
    {
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n - 1; i++)
            g[a[i]].push_back(a[i + 1]);
    }

    if (n == 1)
        return true;
    return !isCycle(n);
}

int main()
{
    FASTIO
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