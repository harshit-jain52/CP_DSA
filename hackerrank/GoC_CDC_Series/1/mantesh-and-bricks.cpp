#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> seg;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        seg.push_back({l, r});
    }
    sort(seg.begin(), seg.end());

    int ans = 0;
    int L = 0, R = -1;
    for (auto p : seg)
    {
        if (p.first > R)
        {
            ans += (R - L + 1);
            L = p.first, R = p.second;
        }
        else
            R = max(R, p.second);
    }
    ans += (R - L + 1);
    cout << ans;
}