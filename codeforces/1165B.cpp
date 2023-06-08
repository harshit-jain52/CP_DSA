#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k = 1, i;
    cin >> n;
    int arr[n];

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (i = 1; i < n; i++)
    {
        if (k + 1 <= arr[i])
        {
            k++;
        }
    }

    cout << k;

    return 0;
}