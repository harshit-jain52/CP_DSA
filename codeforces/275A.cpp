#include <bits/stdc++.h>
using namespace std;

int input[5][5], output[5][5]; // global arrays are initialized to 0
int main()
{
    int i, j;
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            cin >> input[i][j];
        }
    }

    for (i = 1; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            output[i][j] = ((input[i][j] + input[i - 1][j] + input[i + 1][j] + input[i][j - 1] + input[i][j + 1]) + 1) % 2;
        }
    }

    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            cout << output[i][j];
        }
        cout << endl;
    }
}