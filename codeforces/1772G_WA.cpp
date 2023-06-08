#include <bits/stdc++.h>
using namespace std;

void bubbleSort(long long int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int T, n, i, j;
    long long int x, y, temp, count;
    long long int arr[200000];

    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n >> x >> y;

        for (j = 0; j < n; ++j)
        {
            cin >> arr[j];
        }

        bubbleSort(arr, n);
        
        temp = x;
        count = 0;
        while (1)
        {
            for (j = 0; j < n; ++j)
            {
                if (x >= arr[j])
                {
                    x++;
                }
                else
                {
                    x--;
                }
                count++;
                if (x == y)
                {
                    cout << count << endl;
                    goto end;
                }
            }

            if (x <= temp)
            {
                cout << -1 << endl;
                goto end;
            }
        }
    end:;
    }

    return 0;
}