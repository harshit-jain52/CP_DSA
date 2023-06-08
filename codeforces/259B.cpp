#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row1[3], row2[3], row3[3], i;
    for (i = 0; i < 3; i++)
    {
        cin >> row1[i];
    }
    for (i = 0; i < 3; i++)
    {
        cin >> row2[i];
    }
    for (i = 0; i < 3; i++)
    {
        cin >> row3[i];
    }

    int sum1 = accumulate(row1, row1 + 3, 0);
    int sum2 = accumulate(row2, row2 + 3, 0);
    int sum3 = accumulate(row3, row3 + 3, 0);

    int diff21 = sum2 - sum1, diff31 = sum3 - sum1;

    int temp;
    for (temp = 0;; temp++)
    {
        if (2 * temp == sum1 + diff21 + diff31)
        {
            break;
        }
    }

    row1[0] = temp;
    row2[1] = temp - diff21;
    row3[2] = temp - diff31;

    for (i = 0; i < 3; i++)
    {
        cout << row1[i] << " ";
    }
    cout << '\n';
    for (i = 0; i < 3; i++)
    {
        cout << row2[i] << " ";
    }
    cout << '\n';
    for (i = 0; i < 3; i++)
    {
        cout << row3[i] << " ";
    }
}