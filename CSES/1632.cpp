#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pp;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<pp> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    multiset<int> ms;

    while (k--)
        ms.insert(0);

    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = ms.lower_bound(-v[i].second);
        if (it != ms.end())
        {
            ct++;
            ms.erase(it);
            ms.insert(-v[i].first);
        }
    }

    cout << ct;
}