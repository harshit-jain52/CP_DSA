#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int main()
{
    long long int n, x, y, res;
    cin >> x >> y >> n;

    switch (n % 6)
    {
    case 1:
        res = (x);
        break;
    case 2:
        res = (y);
        break;
    case 3:
        res = (y - x);
        break;
    case 4:
        res = (-x);
        break;
    case 5:
        res = (-y);
        break;
    case 0:
        res = (x - y);
        break;
    }

    res = res >= 0 ? res % M : (2*M + res) % M;
    cout << res;
}