#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e6 + 5;
ll dp[N];

ll func(int n)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    string str = to_string(n);
    unordered_set<int> st;
    for (auto c : str)
    {
        st.insert(c - '0');
    }
    ll ans = N;
    for (auto num : st)
    {
        if (n >= num && num != 0)
        {
            ans = min(ans, 1 + func(n - num));
        }
    }

    return dp[n] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    cout << func(n);
}