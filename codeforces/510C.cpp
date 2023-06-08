#include <bits/stdc++.h>
using namespace std;

vector<int> g[26];
vector<int> recur_stack(26, 0);
vector<int> order(26, 0);
vector<int> hasParent(26, 0);
vector<int> vis(26, 0);
vector<int> ans;
unordered_set<int> set1, set2;

bool detectCycle(int vertex)
{
    recur_stack[vertex] = 1;
    vis[vertex] = 1;
    set2.insert(vertex);
    bool ans = false;

    for (auto child : g[vertex])
    {
        if (recur_stack[child])
        {
            ans = true;
            break;
        }
        if (vis[child])
            continue;

        ans |= detectCycle(child);
    }

    recur_stack[vertex] = 0;

    return ans;
}

void dfs(int v)
{
    vis[v] = 1;
    for (int child : g[v])
    {
        if (!vis[child])
            dfs(child);
    }
    ans.push_back(v);
}

void topological_sort()
{
    vis.assign(26, 0);
    ans.clear();
    for (int i = 0; i < 26; ++i)
    {
        if (!vis[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    vector<string> v(n);

    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int flag = 1;

    for (i = 0; i < n - 1; i++)
    {
        string s1 = v[i], s2 = v[i + 1];

        for (int j = 0;; j++)
        {
            if (s1[j] == '\0')
            {
                break;
            }
            if (s2[j] == '\0')
            {
                flag = 0;
                break;
            }

            if (s1[j] == s2[j])
            {
                continue;
            }

            g[s1[j] - 'a'].push_back(s2[j] - 'a');
            hasParent[s2[j] - 'a'] = 1;
            set1.insert(s1[j] - 'a');
            set1.insert(s2[j] - 'a');
            break;
        }

        if (!flag)
        {
            break;
        }
    }
    if (flag)
    {
        // POSSIBLE?

        bool isCycle = false;

        for (i = 0; i < 26; i++)
        {
            if (!hasParent[i] && set1.find(i) != set1.end())
            {
                isCycle |= detectCycle(i);
            }
        }

        if (isCycle || set1.size() != set2.size())
        {
            cout << "Impossible";
        }
        else
        {
            topological_sort();
            for (int it : ans)
            {
                cout << char('a' + it);
            }
        }
    }
    else
    {
        cout << "Impossible";
    }
}