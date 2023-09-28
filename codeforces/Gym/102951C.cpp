#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    int pos_a[n + 1]; // position of i in a,b

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos_a[a[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    int pos[n + 1]; // pos of b(i) in a

    for (int i = 1; i <= n; i++)
    {
        pos[i] = pos_a[b[i]];
    }

    vector<int> dp(n + 1, INF);
    dp[0] = -INF;

    for (int i = 1; i <= n; i++)
    {
        int len = lower_bound(dp.begin(), dp.end(), pos[i]) - dp.begin();
        dp[len] = pos[i];
    }

    int maxlen = lower_bound(dp.begin(), dp.end(), INF) - dp.begin() - 1;
    cout << maxlen;
}