#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 3e5 + 5;
int a[20], b[20];
int n;
int dp[N];

int func(int num)
{
    int sz = __builtin_popcount(num);
    if (sz <= 1)
        return 0;
    if (dp[num] != -1)
        return dp[num];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (((num >> i) & 1) && ((num >> j) & 1))
            {
                if (a[i] == a[j] || b[i] == b[j])
                {
                    ans |= (1 ^ func(num ^ (1 << i) ^ (1 << j)));
                }
            }
        }
    }
    return dp[num] = ans;
}

int main()
{
    FASTIO
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    if (func((1 << n) - 1))
        cout << "Takahashi";
    else
        cout << "Aoki";
}