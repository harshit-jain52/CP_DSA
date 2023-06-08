#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, amazing = 0, min, max, temp, i;

    cin >> n;

    cin >> temp; // first contest
    max = min = temp;

    for (i = 0; i < n - 1; i++)
    {
        cin >> temp;
        if (temp < min)
        {
            min = temp;
            amazing++;
        }
        else if (temp > max)
        {
            max = temp;
            amazing++;
        }
    }

    cout << amazing;

    return 0;
}