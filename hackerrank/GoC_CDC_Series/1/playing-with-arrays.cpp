#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[n], minfromleft[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        minfromleft[i] = a[i];
        if (i)
            minfromleft[i] = min(a[i], minfromleft[i - 1]);
    }
    ll ans = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
        ans = max(ans, a[i] - minfromleft[i]);
    cout << ans;
}