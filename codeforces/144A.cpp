#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, max = 0, min = 101, maxindex, minindex, count = 0;
    cin >> n;

    int a[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            maxindex = i;
        }
    }

    for (i = maxindex; i > 0; i--)
    {
        swap(a[i], a[i - 1]);
        count++;
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] <= min)
        {
            min = a[i];
            minindex = i;
        }
    }

    count += n - 1 - minindex;

    cout << count;
}