#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll ans = -1e18;
        ll prefixMax[n], suffixMax[n];
        prefixMax[0] = a[0];
        suffixMax[n - 1] = a[n - 1];

        for (int i = 1; i < n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], a[i]);
            suffixMax[n - i - 1] = max(suffixMax[n - i], a[n - i - 1]);
        }

        for (int j = 1; j < n - 1; j++)
        {
            ans = max(ans, prefixMax[j - 1] * suffixMax[j + 1] - a[j]);
        }

        cout << ans << endl;
    }
}