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
    vector<vector<int>> result = {{1, 0}, {0, 1}};
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
    H --19-> H
    H --07-> S
    S --06-> H
    S --20-> S

    newH = 19*H + 6*S
    newS = 7*H + 20*S
    */

    vector<vector<int>> a = {{19, 7}, {6, 20}};
    cout << matrixExp(a, n)[0][0];
}