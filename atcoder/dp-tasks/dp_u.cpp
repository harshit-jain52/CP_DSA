#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const ll INF = 1e15;

void func(int idx, vector<int> &rem, int mask, int newgrp, ll score_so_far, ll dp[], ll score[])
{
    if (idx < 0)
    {
        dp[mask] = max(dp[mask], score_so_far + score[newgrp]);
        return;
    }

    func(idx - 1, rem, mask, newgrp, score_so_far, dp, score);
    func(idx - 1, rem, mask ^ (1 << rem[idx]), newgrp ^ (1 << rem[idx]), score_so_far, dp, score);
}

int main()
{
    FASTIO
    int n;
    cin >> n;
    ll a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    ll score[(1 << n)];
    ll dp[(1 << n)];

    for (int mask = 0; mask < (1 << n); mask++)
    {
        score[mask] = 0;
        dp[mask] = -INF;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                for (int j = i + 1; j < n; j++)
                    if (mask & (1 << j))
                        score[mask] += a[i][j];
    }

    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> rem;
        for (int i = 0; i < n; i++)
            if (!(mask & (1 << i)))
                rem.push_back(i);

        func(rem.size() - 1, rem, mask, 0, dp[mask], dp, score);
    }

    cout << dp[(1 << n) - 1];
}

// https://www.youtube.com/watch?v=FAQxdm0bTaw&t=12926s