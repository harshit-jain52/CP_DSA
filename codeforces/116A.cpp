#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, max = 0, num = 0, i;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        num = num - a + b;
        if (num > max)
            max = num;
    }

    cout << max;
}