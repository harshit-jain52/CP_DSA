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
    ll x;
    cin >> n >> x;
    ll w[n];

    for (int i = 0; i < n; i++)
        cin >> w[i];

    pair<ll, ll> best[1 << n];
    // best[s] = {rides(s),last(s)}
    // rides(s) = min no. of rides for subset s
    // last(s) = min weight of the last ride

    best[0] = {1, 0};

    for (int s = 1; s < (1 << n); s++)
    {
        best[s] = {n + 1, 0};
        for (int i = 0; i < n; i++)
        {
            if (s & (1 << i))
            {
                auto pp = best[s ^ (1 << i)];

                if (pp.second + w[i] <= x)
                {
                    pp.second += w[i];
                }
                else
                {
                    pp.first++;
                    pp.second = w[i];
                }

                best[s] = min(best[s], pp);
            }
        }
    }

    cout << best[(1 << n) - 1].first;
}