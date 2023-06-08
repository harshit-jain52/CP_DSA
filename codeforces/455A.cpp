#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
vector<int> ct(N, 0);
ll dp[N];

ll func(ll num)
{
    if (num < 1)
        return 0;
    if (dp[num] != -1)
        return dp[num];

    return dp[num] = max(num * ct[num] + func(num - 2), func(num - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp,-1,sizeof(dp));
    
    int n, tmp, maxnum = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        ct[tmp]++;
        maxnum = max(tmp, maxnum);
    }

    cout << func(maxnum);
}