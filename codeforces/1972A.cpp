#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i - diff] > b[i])
            diff++;
    }

    cout << diff << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}