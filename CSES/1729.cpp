#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 1;

int k;
int p[101];
int dp[N];

int func(int num)
{
    if (num == 0)
        return 0;
    if (dp[num] != -1)
        return dp[num];

    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (p[i] > num)
            break;
        ans |= !func(num - p[i]);
    }

    return dp[num] = ans;
}

int main()
{
    FASTIO
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> p[i];
    sort(p, p + k);

    for (int i = 1; i <= n; i++)
    {
        cout << (func(i) ? 'W' : 'L');
    }
}