#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define loop(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const int M = 1e9 + 7;

struct Matrix
{
    int a[2][2];
    Matrix operator*(Matrix other)
    {
        Matrix product{{{0, 0}, {0, 0}}};
        loop(i, 2)
            loop(j, 2)
                loop(k, 2)
                    product.a[i][k] = (product.a[i][k] + (a[i][j] * 1LL * other.a[j][k]) % M) % M;

        return product;
    }
};

Matrix matrixExp(Matrix a, ll n)
{
    Matrix result = {{{0, 1}, {1, 1}}};
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

    ll n;
    cin >> n;

    Matrix fact = {{{0, 1}, {1, 1}}};
    cout << matrixExp(fact, n).a[0][0];
}