#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;

struct Block
{
    int s, w;
    ll v;
    Block() { s = w = v = 0; }

    bool operator<(Block other)
    {
        return (s + w > other.s + other.w);
    }
};

const int M = 1e9 + 7;
const int N = 1e3 + 1;
const int S = 1e4 + 2;
int n;
vector<Block> b;
ll dp[N][S + 1];

ll func(int i, int lim)
{
    if (i == n)
        return 0;
    if (dp[i][lim] != -1)
        return dp[i][lim];

    ll ans = func(i + 1, lim);
    if (lim == S)
        ans = max(ans, b[i].v + func(i + 1, b[i].s));
    else if (lim >= b[i].w)
        ans = max(ans, b[i].v + func(i + 1, min(lim - b[i].w, b[i].s)));

    return dp[i][lim] = ans;
}

int main()
{
    FASTIO
    memset(dp, -1, sizeof(dp));
    cin >> n;
    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> b[i].w >> b[i].s >> b[i].v;

    sort(b.begin(), b.end());
    cout << func(0, S);
}