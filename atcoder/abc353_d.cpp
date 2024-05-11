#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % M;

        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    FASTIO
    int n;
    cin >> n;
    int a[n];
    int pow10sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        string tmp = to_string(a[i]);
        pow10sum = (pow10sum + binExp(10, tmp.size())) % M;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string tmp = to_string(a[i]);
        pow10sum = (pow10sum - binExp(10, tmp.size()) + M) % M;
        ans = (ans + ((a[i] % M) * 1LL * pow10sum) % M) % M;
        ans = (ans + ((a[i] % M) * 1LL * i) % M) % M;
    }
    cout << ans;
}