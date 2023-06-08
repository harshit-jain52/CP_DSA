#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a1, a2, a3, x, y, z;
    cin >> a1 >> a2 >> a3;

    x = sqrt((a1 * a2) / a3);
    y = sqrt((a2 * a3) / a1);
    z = sqrt((a3 * a1) / a2);

    cout << 4 * (x + y + z);
}