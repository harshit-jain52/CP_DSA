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
        ll n, k, catb;
        cin >> n >> k;

        if (n % 2 == 0)
        {
            catb = k % n;
        }
        else
        {
            ll ct = 0;
            if (k >= (n + 1) / 2)
            {
                ct = 1 + (k - (n + 1) / 2) / ((n - 1) / 2);
            }
            catb = (k + ct) % n;
        }
        cout << ((catb == 0) ? n : catb) << endl;
    }
}