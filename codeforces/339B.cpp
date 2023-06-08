#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i;
    long long int time = 0;

    cin >> n >> m;
    int arr[m + 1];
    arr[0] = 1;

    for (i = 1; i < m + 1; i++)
    {
        cin >> arr[i];

        if (arr[i] >= arr[i - 1])
        {
            time += (arr[i] - arr[i - 1]);
        }
        else
        {
            time += (n - arr[i - 1] + 1) + (arr[i] - 1);
        }
    }

    cout << time;

    return 0;
}