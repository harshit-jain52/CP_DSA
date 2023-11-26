#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

const int N = 2e5 + 10;
vector<int> vis(N, false);
vector<int> recur_stack(N, false);
vector<int> ans(N, -1);

void dfs(int v, int t[], stack<int> &path)
{
    vis[v] = true;
    recur_stack[v] = true;
    path.push(v);

    int next = t[v];
    if (vis[next])
    {
        if (recur_stack[next])
        {
            queue<int> q;
            while (path.top() != next)
            {
                q.push(path.top());
                path.pop();
            }
            q.push(path.top());
            path.pop();

            int sz = q.size();
            while (!q.empty())
            {
                ans[q.front()] = sz;
                q.pop();
            }
        }
        else
        {
            ans[v] = ans[next] + 1;
        }
    }
    else
    {
        dfs(next, t, path);
    }

    if (ans[v] == -1)
        ans[v] = ans[next] + 1;
    recur_stack[v] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int t[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            stack<int> st;
            dfs(i, t, st);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}