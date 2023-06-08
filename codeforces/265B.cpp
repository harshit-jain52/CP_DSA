#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll h[n + 1], i, sec = 0;
    h[0] = 0;
    for (i = 1; i < n + 1; i++)
    {
        cin >> h[i];
        sec += abs(h[i] - h[i - 1]);
    }
    sec += n;
    sec += n - 1;

    cout << sec;
}