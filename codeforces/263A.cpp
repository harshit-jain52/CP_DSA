#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, row, col;
    int arr[5][5];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
            {
                row = i;
                col = j;
            }
        }
    }

    cout << abs(row - 2) + abs(col - 2);

    return 0;
}