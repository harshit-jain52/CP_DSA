#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        x1 = min(x1, n - x1 + 1);
        y1 = min(y1, n - y1 + 1);
        x2 = min(x2, n - x2 + 1);
        y2 = min(y2, n - y2 + 1);

        cout << abs(min(x1, y1) - min(x2, y2)) << endl;
    }
}