#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n, m, cost = 0;
        cin >> a >> b >> n >> m;

        if (n <= m)
        {
            cost += n * min(a, b);
        }
        else
        {
            if ((m + 1) * b <= m * a)
            {
                cost += n * b;
            }
            else
            {
                cost += (n / (m + 1)) * m * a;
                cost += (n % (m + 1)) * min(a, b);
            }
        }

        cout << cost << endl;
    }
}