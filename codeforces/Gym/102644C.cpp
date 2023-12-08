#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

vector<vector<int>> matrixMultiply(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> product(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                product[i][k] = (product[i][k] + (a[i][j]*1LL*b[j][k]) % M) % M;

    return product;
}

vector<vector<int>> matrixExp(vector<vector<int>> a, ll n)
{
    vector<vector<int>> result = {{0, 1}, {1, 1}};
    while (n > 0)
    {
        if (n % 2 == 1)
            result = matrixMultiply(a, result);

        a = matrixMultiply(a, a);
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

    /*
    newA = 0*A + 1*B
    newB = 1*A + 1*B
    */

   vector<vector<int>> fact = {{0, 1}, {1, 1}};
   cout << matrixExp(fact,n)[0][0];
}