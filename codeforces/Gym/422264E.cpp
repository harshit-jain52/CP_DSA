#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, sum, dig;
    long long int n, i, j;

    int arr2[4] = {6, 2, 4, 8};
    int arr3[4] = {1, 3, 9, 7};
    int arr4[2] = {6, 4};
    int arr7[4] = {1, 7, 9, 3};
    int arr8[4] = {6, 8, 4, 2};
    int arr9[2] = {1, 9};

    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n;
        sum = 0;

        for (j = 1; j <= n % 100; j++) // repeats after every 100
        {
            dig = j % 10;

            switch (dig)
            {
            case 1:
                sum++;
                break;
            case 2:
                sum += arr2[j % 4];
                break;
            case 3:
                sum += arr3[j % 4];
                break;
            case 4:
                sum += arr4[j % 2];
                break;
            case 5:
                sum += 5;
                break;
            case 6:
                sum += 6;
                break;
            case 7:
                sum += arr7[j % 4];
                break;
            case 8:
                sum += arr8[j % 4];
                break;
            case 9:
                sum += arr9[j % 2];
                break;
            }
        }

        cout << sum % 10 << endl;
    }

    return 0;
}