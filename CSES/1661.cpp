#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    ll x;
    cin >> n >> x;
    ll a[n];
    ll currsum = 0;
    map<ll, int> m;
    
    m[currsum]++;
    ll ct = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        currsum += a[i];

        if (m.find(currsum - x) != m.end())
        {
            ct += m[currsum - x];
        }
        m[currsum]++;
    }

    cout << ct;
}