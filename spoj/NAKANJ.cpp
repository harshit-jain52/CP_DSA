#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7 + 10;
int vis[8][8];
int lvl[8][8];

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            vis[i][j] = 0;
            lvl[i][j] = INF;
        }
    }
}

int getX(string s)
{
    return s[0] - 'a';
}
int getY(string s)
{
    return s[1] - '1';
}

bool isValid(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

vector<pair<int, int>> movements = {
    {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

int bfs(string src, string dest)
{
    int srcX = getX(src);
    int srcY = getY(src);
    int destX = getX(dest);
    int destY = getY(dest);

    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = 1;
    lvl[srcX][srcY] = 0;

    while (!q.empty())
    {
        pair<int, int> cur_v = q.front();
        int x = cur_v.first, y = cur_v.second;
        q.pop();

        for (auto mov : movements)
        {
            int a = x + mov.first, b = y + mov.second;
            if (isValid(a, b) && !vis[a][b])
            {
                q.push({a, b});
                vis[a][b] = 1;
                lvl[a][b] = lvl[x][y] + 1;
            }
        }

        if (lvl[destX][destY] != INF)
            break;
    }

    return lvl[destX][destY];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl;
    }
}