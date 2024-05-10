#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;

int main()
{
    int x, y, i, j;
    cin >> x >> y;
    int a[x + 1], b[y + 1];
    for (i = 0; i < x; i++)
        cin >> a[i];
    for (j = 0; j < y; j++)
        cin >> b[j];
    a[x] = b[y] = N + 2;
    sort(a, a + x);
    sort(b, b + y);
    int xdiff = 1, xlast = 0, ydiff = 1, ylast = 0;
    i = 0;
    j = 0;
    for (int num = 1; num <= N + 1; num++)
    {
        xdiff = max(xdiff, num - xlast);
        ydiff = max(ydiff, num - ylast);

        if (num != a[i])
            xlast = num;
        else
            i++;

        if (num != b[j])
            ylast = num;
        else
            j++;
    }

    cout << xdiff * 1LL * ydiff;
}