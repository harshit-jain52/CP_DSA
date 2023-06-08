#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int n;
ll m;
ll h[N];

bool isWoodSufficient(ll height)
{
    ll wood = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] >= height)
        {
            wood += h[i] - height;
        }
    }
    return (wood >= m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    ll lo = 0, hi = 1e9, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;

        if (isWoodSufficient(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }

    if (isWoodSufficient(hi))
    {
        cout << hi;
    }
    else
    {
        cout << lo;
    }
}