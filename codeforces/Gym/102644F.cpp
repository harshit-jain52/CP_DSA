#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll INF = LONG_LONG_MAX;

vector<vector<ll>> matrixMultiply(vector<vector<ll>> a, vector<vector<ll>> b, int sz)
{
    vector<vector<ll>> product(sz + 1, vector<ll>(sz + 1, INF));
    for (int i = 1; i <= sz; i++)
        for (int j = 1; j <= sz; j++)
            for (int k = 1; k <= sz; k++)
                if (a[i][j] != INF && b[j][k] != INF)
                    product[i][k] = min(product[i][k], (a[i][j] + b[j][k]));

    return product;
}

vector<vector<ll>> matrixExp(vector<vector<ll>> a, ll k, int sz)
{
    vector<vector<ll>> result(sz + 1, vector<ll>(sz + 1, INF));
    for (int i = 1; i <= sz; i++)
        result[i][i] = 0;

    while (k > 0)
    {
        if (k % 2 == 1)
            result = matrixMultiply(a, result, sz);

        a = matrixMultiply(a, a, sz);
        k /= 2;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> graph(n + 1, vector<ll>(n + 1, INF));
    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    ll minPath = INF;
    vector<vector<ll>> res = matrixExp(graph, k, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            minPath = min(minPath, res[i][j]);
        }
    }

    if (minPath != INF)
        cout << minPath;
    else
        cout << "IMPOSSIBLE";
}