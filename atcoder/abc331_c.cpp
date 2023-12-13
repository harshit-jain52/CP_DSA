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

    int n;
    cin >> n;

    ll a[n];
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v[i] = a[i];
    }

    sort(v.begin(), v.end());

    ll suff[n + 1];
    suff[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        suff[i] = suff[i + 1] + v[i];

    for (int i = 0; i < n; i++)
        cout << suff[upper_bound(v.begin(), v.end(), a[i]) - v.begin()] << " ";
}