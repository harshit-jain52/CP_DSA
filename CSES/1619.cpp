#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    sort(v.begin(), v.end());
    int ct = 0, ans = 0;

    for (auto it : v)
    {
        ct += it.second;
        ans = max(ans, ct);
    }

    cout << ans;
}