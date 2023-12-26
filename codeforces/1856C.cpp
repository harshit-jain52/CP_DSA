#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

bool check(ll target, int a[], int n, int k)
{
    ll minmoves = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] >= target)
            return true;
        int idx = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] >= target - (j - i))
            {
                idx = j;
                break;
            }
        }
        if (idx == -1)
            continue;
        ll moves = 0;
        for (int j = idx - 1; j >= i; j--)
        {
            moves += target - (j - i) - a[j];
        }
        minmoves = min(minmoves, moves);
    }

    return minmoves <= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll lo = *max_element(a, a + n), hi = 1e16 + 1, mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        if (check(mid, a, n, k))
            lo = mid;
        else
            hi = mid - 1;
    }

    if (check(hi, a, n, k))
        cout << hi;
    else
        cout << lo;

    cout << endl;
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