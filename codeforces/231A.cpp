#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum, temp;
    int count = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        sum = 0;

        for (int j = 0; j < 3; j++)
        {
            cin >> temp;
            sum += temp;
        }

        if (sum >= 2)
        {
            count++;
        }
    }

    cout << count;
    return 0;
}