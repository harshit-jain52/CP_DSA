#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
#define pp pair<int, int>

const int N = 1e3 + 2;
const int INF = 1e7;

char labyrinth[N][N];
int level[N][N];
int n, m;

vector<pp> steps{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string movements = "UDLR";

void bfs(int x, int y)
{
    queue<pp> q;
    q.push({x, y});
    level[x][y] = 0;

    while (!q.empty())
    {
        pp cur = q.front();
        q.pop();

        for (auto next : steps)
        {
            int next_x = cur.first + next.first;
            int next_y = cur.second + next.second;

            if (next_x <= 0 || next_x > n || next_y <= 0 || next_y > m || labyrinth[next_x][next_y] == '#')
                continue;

            if (level[next_x][next_y] == INF)
            {
                q.push({next_x, next_y});
                level[next_x][next_y] = level[cur.first][cur.second] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    pp start, end;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> labyrinth[i][j];
            level[i][j] = INF;

            if (labyrinth[i][j] == 'A')
                start = {i, j};

            if (labyrinth[i][j] == 'B')
                end = {i, j};
        }
    }

    bfs(start.first, start.second);
    int len = level[end.first][end.second];

    if (len == INF)
        cout << "NO";
    else
        cout << "YES" << endl
             << len << endl;

    int lev = len;
    int cur_x = end.first, cur_y = end.second, prev_x, prev_y;
    string path = "";

    while (lev > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            auto prev = steps[i];
            prev_x = cur_x + prev.first;
            prev_y = cur_y + prev.second;

            if (prev_x <= 0 || prev_x > n || prev_y <= 0 || prev_y > m)
                continue;
            if (level[prev_x][prev_y] == lev - 1)
            {
                path.push_back(movements[i]);
                break;
            }
        }

        lev--;
        cur_x = prev_x;
        cur_y = prev_y;
    }

    reverse(path.begin(), path.end());
    cout << path;
}