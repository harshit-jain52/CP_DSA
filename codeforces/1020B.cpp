#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

const int N = 1e3 + 10;
vector<int> vis(N, false);
vector<int> recur_stack(N, false);
vector<int> ans(N, -1);

void dfs(int v, int p[], stack<int> &path)
{
    vis[v] = true;
    recur_stack[v] = true;
    path.push(v);

    int next = p[v];
    if (vis[next])
    {
        if (recur_stack[next])
        {
            queue<int> q;
            while (path.top() != next)
            {
                ans[path.top()] = path.top();
                path.pop();
            }
            ans[path.top()] = path.top();
            path.pop();
        }
        else
        {
            ans[v] = ans[next];
        }
    }
    else
    {
        dfs(next, p, path);
    }

    if (ans[v] == -1)
        ans[v] = ans[next];
    recur_stack[v] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int p[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            stack<int> st;
            dfs(i, p, st);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}