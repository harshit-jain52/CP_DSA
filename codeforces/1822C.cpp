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
        ll n, sum = 1;
        cin >> n;

        // 4*n + (n-1) + 2*(n-2 + n-3 +.....+1) + 1

        sum += 4 * n + (n - 1);
        sum += (n - 2) * (n - 1);

        cout << sum << endl;
    }
}