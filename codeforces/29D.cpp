#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 310;
vector<int> g[N];
vector<bool> vis(N, false);
vector<vector<int>> branches(N);
int k = 0;

void dfs(int vertex, vector<int> &v)
{
    v.push_back(vertex);
    vis[vertex] = true;

    if (g[vertex].size() == 1 && vertex != 1)
    {
        branches[vertex] = v;
        k++;
    }
    for (auto child : g[vertex])
    {
        if (vis[child])
            continue;

        dfs(child, v);
        v.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> v;
    dfs(1, v);

    vector<int> leaves;
    for (int i = 0; i < k; i++)
    {
        int l;
        cin >> l;
        leaves.push_back(l);
    }

    // for (int i = 0; i < k; i++)
    // {
    //     for (auto it : branches[leaves[i]])
    //     {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> to_print;

    for (int i = 0; i < branches[leaves[0]].size() - 1; i++)
    {
        to_print.push_back(branches[leaves[0]][i]);
    }

    for (int i = 1; i < k; i++)
    {
        vector<int> v1 = branches[leaves[i - 1]];
        vector<int> v2 = branches[leaves[i]];
        int idx;
        for (int j = 0; j < min(v1.size(), v2.size()); j++)
        {
            if (v1[j] != v2[j])
            {
                idx = j;
                break;
            }
        }

        for (int j = v1.size() - 1; j >= idx - 1; j--)
        {
            to_print.push_back(v1[j]);
        }
        for (int j = idx; j < v2.size() - 1; j++)
        {
            to_print.push_back(v2[j]);
        }
    }

    for (int i = branches[leaves[k - 1]].size() - 1; i >= 0; i--)
    {
        to_print.push_back(branches[leaves[k - 1]][i]);
    }

    if (to_print.size() > 2 * n - 1)
        cout << -1;
    else
    {
        for (auto it : to_print)
        {
            cout << it << " ";
        }
    }
}