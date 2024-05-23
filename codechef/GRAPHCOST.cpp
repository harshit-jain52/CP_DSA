#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll dp[n];
    stack<int> st;
    set<pair<int, int>> justg;

    dp[n - 1] = 0;
    justg.insert({a[n - 1], n - 1});
    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] > a[i])
            st.pop();
        if (!st.empty())
        {
            int nle = st.top();
            dp[i] = dp[nle] + (nle - i) * 1LL * a[i];
        }
        else
        {
            int ng = (*(justg.upper_bound({a[i], -1}))).second;
            dp[i] = dp[ng] + (ng - i) * 1LL * a[ng];
        }
        st.push(i);
        justg.insert({a[i], i});
    }
    cout << dp[0] << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}