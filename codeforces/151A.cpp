#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    int toast1, toast2, toast3;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    toast1 = (k * l) / nl;
    toast2 = c * d;
    toast3 = p / np;

    cout << (min(toast1, min(toast2, toast3))) / n;

    return 0;
}