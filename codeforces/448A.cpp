#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a1, a2, a3, b1, b2, b3, a, b, m;

    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;

    a = a1 + a2 + a3;
    b = b1 + b2 + b3;

    m = (a / 5 + (int)(a % 5 != 0)) + (b / 10 + (int)(b % 10 != 0));

    if (m <= n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}