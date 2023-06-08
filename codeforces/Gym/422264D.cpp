#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    double xa, xb, ya, yb, dist;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> xa >> ya >> xb >> yb;

        dist = sqrt((xa - xb) * (xa - xb) + (ya + yb) * (ya + yb));

        cout << setprecision(13) << dist << endl;
    }

    return 0;
}