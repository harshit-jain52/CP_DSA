#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

// Problem: N <= 1000 items, each with some weight wi. Is there a subset of items with total weight = W (<= 1e6) ?

const int MAX_W = 1e6 + 5;
bitset<MAX_W> dp;

int main()
{
    int n, W;
    cin >> n >> W;
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        dp |= (dp << w);
    }
    cout << (dp[W] ? "YES" : "NO");
}

// TC: O(n*W/32)