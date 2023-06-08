#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ct(n + 1);
    ct[0] = 0;
    for (int i = 0; i < n; i++)
    {
        ct[i + 1] = ct[i] + (s[i] == '1');
    }

    ll ans = 0;
    int tmp = k;
    while (ct[n] >= tmp)
    {
        auto it1 = upper_bound(ct.begin(), ct.end(), tmp - k);
        auto it2 = lower_bound(ct.begin(), ct.end(), tmp - k);
        auto it3 = upper_bound(ct.begin(), ct.end(), tmp);
        auto it4 = upper_bound(ct.begin(), ct.end(), tmp - 1);
        if (k != 0)
        {
            ans += (it1 - it2) * 1LL * (it3 - it4);
        }
        else
        {
            ans += (it1 - it2 - 1LL) * (it1 - it2) / 2;
        }
        tmp++;
    }
    cout << ans;

    // for (auto it : ct)
    // {
    //     cout << it << " ";
    // }
}