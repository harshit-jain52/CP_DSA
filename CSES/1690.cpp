#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 20;

vector<int> graph[N];
int dp[N][1 << N];

int hamiltonian(int v, int mask, int n)
{
    if (v == n - 1)
        return (__builtin_popcount(mask) == n);

    if (dp[v][mask] != -1)
        return dp[v][mask];

    int ans = 0;
    for (int next : graph[v])
        if (((1 << next) & mask) == 0)
            ans = (ans + hamiltonian(next, ((1 << next) | mask), n)) % M;

    return dp[v][mask] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    cout << hamiltonian(0, 1, n);
}