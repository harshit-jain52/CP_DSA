#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long double ld;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ld d, h;
        cin >> n >> d >> h;

        ld y[n];
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
        }

        ld ratio = d / h;
        ld area = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (y[i + 1] >= y[i] + h)
            {
                area += 0.5 * d * h;
            }
            else
            {
                area += 0.5 * d * h - 0.5 * ratio * (y[i] + h - y[i + 1]) * (y[i] + h - y[i + 1]);
            }
        }
        area += 0.5 * d * h;

        printf("%.7Lf\n",area);
    }
}