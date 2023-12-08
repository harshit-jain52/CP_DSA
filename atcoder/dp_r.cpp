#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

vector<vector<int>> matrixMultiply(vector<vector<int>> a, vector<vector<int>> b, int sz)
{
    vector<vector<int>> product(sz + 1, vector<int>(sz + 1, 0));
    for (int i = 1; i <= sz; i++)
        for (int j = 1; j <= sz; j++)
            for (int k = 1; k <= sz; k++)
                product[i][k] = (product[i][k] + (a[i][j] * 1LL * b[j][k]) % M) % M;

    return product;
}

vector<vector<int>> matrixExp(vector<vector<int>> a, ll n, int sz)
{
    vector<vector<int>> result(sz + 1, vector<int>(sz + 1, 0));
    for (int i = 1; i <= sz; i++)
        result[i][i] = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
            result = matrixMultiply(a, result, sz);

        a = matrixMultiply(a, a, sz);
        n /= 2;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int sum = 0;
    vector<vector<int>> res = matrixExp(graph, k, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum = (sum + res[i][j]) % M;
        }
    }

    cout << sum << endl;
}