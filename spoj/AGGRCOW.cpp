#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int n, c;
ll stalls[N];

bool isAssignmentPossible(ll dist)
{
    ll prev = stalls[0];
    int ct = 1;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - prev >= dist)
        {
            ct++;
            prev = stalls[i];
        }

        if (ct == c)
        {
            break;
        }
    }
    return (ct == c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;

        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        sort(stalls, stalls + n);

        ll lo = 0, hi = 1e9, mid;
        while (hi - lo > 1)
        {
            mid = (lo + hi) / 2;

            if (isAssignmentPossible(mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        if (isAssignmentPossible(hi))
        {
            cout << hi;
        }
        else
        {
            cout << lo;
        }
        cout << endl;
    }
}