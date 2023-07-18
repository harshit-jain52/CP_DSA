#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int func(int idx, vector<int> &start, vector<int> &end, vector<int> &dp)
{
    if (dp[idx] != -1)
        return dp[idx];

    int ans = 1;
    int add = 0;
    auto it = lower_bound(start.begin(), start.end(), end[idx]);
    while (it != start.end())
    {
        add = max(add, func(it - start.begin(), start, end, dp));
        it++;
    }
    return dp[idx] = ans + add;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> time(n);
    vector<int> start(n), end(n), dp(n, -1);

    for (int i = 0; i < n; i++)
    {
        cin >> time[i].first >> time[i].second;
    }
    sort(time.begin(), time.end());

    for (int i = 0; i < n; i++)
    {
        start[i] = time[i].first;
        end[i] = time[i].second;
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, func(i, start, end, dp));
    }

    cout << ans;
}