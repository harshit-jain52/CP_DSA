#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define loop(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

struct Matrix
{
    unsigned int arr[65][65];
    Matrix operator*(Matrix other)
    {
        Matrix product{{{0, 0}, {0, 0}}};
        loop(i, 65)
            loop(j, 65)
                loop(k, 65)
                    product.arr[i][k] = product.arr[i][k] + arr[i][j] * 1LL * other.arr[j][k];

        return product;
    }
};

Matrix matrixExp(Matrix a, int k)
{
    Matrix result;
    loop(i, 65)
        loop(j, 65)
            result.arr[i][j] = (i==j);

    while (k > 0)
    {
        if (k % 2 == 1)
            result = a * result;

        a = a * a;
        k /= 2;
    }

    return result;
}

bool isValid(int row, int col)
{
    return (min(row, col) >= 0 && max(row, col) < 8);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    /*
    dp[new_row][new_col] += dp[new][col] for every possible new_row,new_col from row,col
    ans += dp[new_row][new_col] at every iteration

    linear dp: dp[65]; 0..63: cells; 64: ans
    new_dp[8*new_row+new_col] += dp[8*row+col]
    */

    Matrix board;
    loop(i, 65)
        loop(j, 65)
            board.arr[i][j] = 0;

    vector<pair<int, int>> moves{
        {1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};

    loop(row, 8)
    {
        loop(col, 8)
        {
            for (auto [dr, dc] : moves)
            {
                int new_row = row + dr;
                int new_col = col + dc;

                if (isValid(new_row, new_col))
                {
                    board.arr[8 * row + col][8 * new_row + new_col] = 1;
                }
            }
        }
    }

    loop(i, 65)
        board.arr[i][64] = 1;

    Matrix total = matrixExp(board, k+1);
    cout << total.arr[0][64];
}