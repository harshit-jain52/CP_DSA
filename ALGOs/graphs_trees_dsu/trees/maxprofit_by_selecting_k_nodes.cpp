#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const ll INF = 1e15;

/*
Problem:
Maximize profit by selecting atmost k nodes; no 2 neighbors should be selected
*/

vector<int> g[N];
int sz[N];
ll profit[N];
ll dp[N][2][N]; // dp[node][isThisNodeIncluded][num_of_nodes_included]

ll dfs(int nn, int pp)
{
    sz[nn] = 1;
    for (int k = 0; k < N; k++)
        dp[nn][0][k] = dp[nn][1][k] = -INF;

    dp[nn][0][0] = 0;
    dp[nn][1][1] = profit[nn];

    for (auto v : g[nn])
    {
        if (v == pp)
            continue;

        dfs(v, nn);

        for (int i = sz[nn]; i >= 0; i--) // Important!! bcoz of this line, TC: O(N^3) -> O(N^2)
        {
            for (int j = sz[v]; j >= 0; j--)
            {
                dp[nn][0][i + j] = max(dp[nn][0][i + j], dp[nn][0][i] + max(dp[v][0][j], dp[v][1][j]));
                dp[nn][1][i + j] = max(dp[nn][1][i + j], dp[nn][1][i] + dp[v][0][j]);
            }
        }
        // ^ similar to flloyd warshall & knapsack

        sz[nn] += sz[v];
    }
}