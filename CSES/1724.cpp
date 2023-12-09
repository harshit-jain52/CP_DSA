#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define loop(i, n) for (int i = 1; i < n; i++)
typedef long long ll;
const ll INF = LONG_LONG_MAX;

struct Matrix
{
    ll arr[101][101];
    Matrix operator*(Matrix other)
    {
        Matrix product;
        loop(i, 101) loop(j, 101) product.arr[i][j] = INF;

        loop(i, 101)
            loop(j, 101)
                loop(k, 101) if (arr[i][j] != INF && other.arr[j][k] != INF)
                    product.arr[i][k] = min(product.arr[i][k], (arr[i][j] + other.arr[j][k]));

        return product;
    }
};

Matrix matrixExp(Matrix a, ll k)
{
    Matrix result;
    loop(i, 101)
        loop(j, 101)
            result.arr[i][j] = (i == j) ? 0 : INF;

    while (k > 0)
    {
        if (k % 2 == 1)
            result = a * result;

        a = a * a;
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
    Matrix graph;

    loop(i, 101)
        loop(j, 101)
            graph.arr[i][j] = INF;

    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph.arr[a][b] = min(graph.arr[a][b], c);
    }

    ll minPath = matrixExp(graph, k).arr[1][n];

    if (minPath != INF)
        cout << minPath;
    else
        cout << -1;
}