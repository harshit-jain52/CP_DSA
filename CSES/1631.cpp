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
    ll t[n];

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        sum += t[i];
    }

    ll last = *max_element(t, t + n);
    sum -= last;

    if (last > sum)
        cout << 2 * last;
    else
        cout << sum + last;
}