#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int to_insert;
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                to_insert = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = to_insert;
            }
        }
    }
}

int main()
{
    int can[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> can[i];
    }

    insertionSort(can, 4);

    if (can[0] + can[3] == can[1] + can[2])
    {
        cout << "YES";
    }
    else if (can[0] + can[1] + can[2] == can[3])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}