#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int SIZE = 22;
const int INF = 1e9;

/*
Travelling Salesman Problem (Hamiltonian Walk on graph)
Given a list of n cities and the cost of travelling between each pair of cities,
what is the cheapest possible route that visits each city exactly once and returns to the origin city (city 1)

1<=n<=20
*/

ll dp[SIZE][1 << SIZE];

ll tsp(int idx, int mask, int n, vector<vector<ll>> &cost) // set bit in mask indicates unvisitied city
{
    if (mask == 1)
        return cost[idx][0]; // returning to city 1

    if (dp[idx][mask] != -1)
        return dp[idx][mask];

    ll ans = INF;

    for (int j = 1; j < n; j++)
    {
        if ((mask & (1 << j)) != 0)
            ans = min(ans, cost[idx][j] + tsp(j, (mask ^ (1 << j)), n, cost));
    }

    return dp[idx][mask] = ans;
}
// TC : O(n^2 * 2^n)

int main()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    vector<vector<ll>> cost(n, vector<ll>(n));

    for (int i = 0; i < n; i++) // 0-based indexing
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j]; // cost from city i+1 to city j+1
        }
    }

    ll ans = tsp(0, (1 << n) - 1, n, cost);
    cout << ans;
}