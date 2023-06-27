#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

char arr[1005][1005];
bool vis[1005][1005];
int n, m;

void dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;

    if (arr[i][j] == '#' || vis[i][j])
        return;

    vis[i][j] = true;

    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            vis[i][j] = false;
        }
    }
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.' && !vis[i][j])
            {
                ct++;
                dfs(i, j);
            }
        }
    }

    cout << ct;
}