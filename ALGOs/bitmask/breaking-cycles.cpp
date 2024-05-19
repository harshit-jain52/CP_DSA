#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

/*
Problem: Given a directed graph, we need to remove minimum number of edges to make it acyclic.
Idea: DAG has at least one topo order. Generate a topo order (a permutation) and remove backward edges.
*/

const int N = 20;
int dp[1 << N];
int numEdge[N][N]; // numEdge[i][j] =  no. of edges from i to j

int bestChoice(int pos, int mask)
{
    if (pos == N)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int ans = 1e9;
    for (int i = 0; i < N; i++)
    {
        if (mask & (1 << i))
            continue;

        int tmpct = 0;
        for (int j = 0; j < N; j++)
        {
            if (mask & (1 << j))
                tmpct += numEdge[i][j];
        }
        ans = min(ans, tmpct + bestChoice(pos + 1, mask | (1 << i)));
    }

    return dp[mask] = ans; // no need to store pos in dp as pos = __builtin_popcount(mask)
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        numEdge[u][v]++;
    }

    cout << bestChoice(0, 0);
}