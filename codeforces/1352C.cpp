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
        ll n, k, ans, prev;
        cin >> n >> k;
        prev = k;
        ans = k + k / n;

        while (prev / n < ans / n)
        {
            prev = ans;
            ans = k + ans / n;
        }

        if (ans % n == 0)
        {
            ans++;
        }

        cout << ans << endl;
    }
}