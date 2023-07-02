#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int x[n];
    unordered_set<int> dp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    dp[0].insert(0);
    dp[0].insert(x[0]);

    for (int i = 1; i < n; i++)
    {
        for (auto it : dp[i - 1])
        {
            dp[i].insert(it);
            dp[i].insert(it + x[i]);
        }
    }

    vector<int> to_print;
    for (auto it : dp[n - 1])
    {
        to_print.push_back(it);
    }
    sort(to_print.begin(), to_print.end());
    int num = to_print.size();
    cout << num - 1 << endl;
    for (int i = 1; i < num; i++)
    {
        cout << to_print[i] << " ";
    }
}