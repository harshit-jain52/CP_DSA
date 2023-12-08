#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define loop(i, n) for (int i = 1; i < n; i++)
typedef long long ll;
const int M = 1e9 + 7;

struct Matrix
{
    int arr[101][101];
    Matrix operator*(Matrix other)
    {
        Matrix product{{{0, 0}, {0, 0}}};
        loop(i, 101)
            loop(j, 101)
                loop(k, 101)
                    product.arr[i][k] = (product.arr[i][k] + (arr[i][j] * 1LL * other.arr[j][k]) % M) % M;

        return product;
    }
};

Matrix matrixExp(Matrix a, ll n)
{
    Matrix result;
    loop(i, 101)
        loop(j, 101)
            result.arr[i][j] = (i == j);

    while (n > 0)
    {
        if (n % 2 == 1)
            result = a * result;

        a = a * a;
        n /= 2;
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
            graph.arr[i][j] = 0;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph.arr[a][b]++;
    }

    cout << matrixExp(graph, k).arr[1][n];
}