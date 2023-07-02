#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e5 + 1;

int dp[1001][N];
pair<int, int> books[1001];

int func(int idx, int money_left)
{
    if (money_left == 0 || idx < 0)
        return 0;

    if (dp[idx][money_left] != -1)
        return dp[idx][money_left];

    int ans = 0;
    if (books[idx].first <= money_left)
    {
        ans = max(ans, books[idx].second + func(idx - 1, money_left - books[idx].first));
    }
    ans = max(ans, func(idx - 1, money_left));

    return dp[idx][money_left] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> books[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> books[i].second;
    }
    sort(books, books + n);

    int start = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (books[i].first <= x)
        {
            start = i;
            break;
        }
    }
    cout << func(start, x);
}