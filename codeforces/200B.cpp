#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, temp;
    float sum = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        sum += temp;
    }

    cout << setprecision(6) << (sum / n);

    return 0;
}