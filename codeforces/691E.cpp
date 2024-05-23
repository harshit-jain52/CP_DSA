#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

class Matrix
{
public:
    vector<vector<int>> mat;
    Matrix(int sz)
    {
        mat.assign(sz, vector<int>(sz, 0));
    }

    Matrix operator=(const Matrix &other)
    {
        mat = other.mat;
        return *this;
    }

    Matrix identity()
    {
        int sz = mat.size();
        Matrix I(sz);
        for (int i = 0; i < sz; i++)
            I.mat[i][i] = 1;
        return I;
    }

    Matrix operator*(const Matrix &other)
    {
        int sz = mat.size();
        Matrix prod(sz);
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++)
                    prod.mat[i][j] = (prod.mat[i][j] + (mat[i][k] * 1LL * other.mat[k][j]) % M) % M;

        return prod;
    }

    Matrix binExp(ll n)
    {
        Matrix ans = identity();
        Matrix a = *this;
        while (n)
        {
            if (n & 1)
                ans = ans * a;
            a = a * a;
            n >>= 1;
        }
        return ans;
    }
};

int main()
{
    FASTIO
    int n;
    ll k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ct = __builtin_popcountll(a[i] ^ a[j]);
            if (ct % 3 == 0)
                adj[i][j] = 1;
        }
    }

    Matrix m(n);
    m.mat = adj;
    Matrix res = m.binExp(k - 1);
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ct = (ct + res.mat[i][j]) % M;
        }
    }
    cout << ct;
}