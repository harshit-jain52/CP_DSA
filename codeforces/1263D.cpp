#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_set<int> g[26];

bool vis[26];
bool isPresent[26];
void dfs(int v)
{
    vis[v] = true;

    for (auto it : g[v])
    {
        if (!vis[it])
            dfs(it);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, string>> v;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            isPresent[str[j] - 'a'] = true;
        }

        for (int j = 1; j < str.size(); j++)
        {
            g[str[j - 1] - 'a'].insert(str[j] - 'a');
            g[str[j] - 'a'].insert(str[j - 1] - 'a');
        }
    }

    int ct = 0;
    for (int i = 0; i < 26; i++)
    {
        if (!vis[i] && isPresent[i])
        {
            ct++;
            dfs(i);
        }
    }

    cout << ct;
}