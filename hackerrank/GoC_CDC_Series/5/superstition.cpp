#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    stack<pair<char, int>> st;
    int curr = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i < n && s[i] == s[i - 1])
            curr++;
        else
        {

            if (!st.empty() && st.top().first == s[i - 1])
            {
                curr += st.top().second;
                st.pop();
            }
            if (curr % k)
                st.push({s[i - 1], curr % k});
            curr = 1;
        }
    }

    string ans = "";
    while (!st.empty())
    {
        auto p = st.top();
        st.pop();
        for (int i = 0; i < p.second; i++)
            ans.push_back(p.first);
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
}