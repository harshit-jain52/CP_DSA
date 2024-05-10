#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
            odd.push_back(i);
        else
            even.push_back(i);
    }

    sort(a, a + n);
    ll ans[n];
    int o = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & 1)
            ans[odd[o++]] = a[i];
        else
            ans[even[e++]] = a[i];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}