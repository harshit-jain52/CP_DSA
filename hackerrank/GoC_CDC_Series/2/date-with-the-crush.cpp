#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
#define X first
#define Y second
vector<ppi> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    ppi start, end;

    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];

        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 'R')
                start = {i, j};
            if (grid[i][j] == 'E')
                end = {i, j};
        }
    }

    queue<ppi> q;
    int dist[N][M];
    vector<vector<bool>> vis(N, vector<bool>(M, false));

    q.push(start);
    dist[start.X][start.Y] = 0;

    while (!q.empty())
    {
        ppi curr = q.front();
        q.pop();
        if (curr == end)
            break;

        for (auto m : moves)
        {
            ppi next = {curr.X + m.X, curr.Y + m.Y};
            if (next.X < 0 || next.Y < 0 || next.X >= N || next.Y >= M || grid[next.X][next.Y] == 'P' || vis[next.X][next.Y])
                continue;
            dist[next.X][next.Y] = 1 + dist[curr.X][curr.Y];
            vis[next.X][next.Y] = true;
            q.push(next);
        }
    }

    cout << dist[end.X][end.Y];
}