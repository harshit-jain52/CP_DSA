#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

ll diff = INT_MAX;
ll sum = 0;
int n;

void func(int idx, ll p[], ll tmpsum)
{
    if (idx >= n)
    {
        diff = min(diff, abs(sum - 2 * tmpsum));
        return;
    }

    func(idx + 1, p, tmpsum + p[idx]);
    func(idx + 1, p, tmpsum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    ll p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        sum += p[i];
    }

    func(0, p, 0);

    cout << diff;
}