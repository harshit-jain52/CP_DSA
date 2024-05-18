#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    FASTIO
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a >> c[i];
        vec.push_back({a, i});
    }
    vector<int> ans;
    sort(vec.begin(), vec.end());

    // for(auto p: vec) cout<< p.first<<" "<<p.second+1<<endl;
    int mincost = c[vec[n - 1].second];
    ans.push_back(vec[n - 1].second);

    for (int i = n - 2; i >= 0; i--)
    {
        if (c[vec[i].second] <= mincost)
            ans.push_back(vec[i].second);
        mincost = min(mincost, c[vec[i].second]);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans)
        cout << i + 1 << " ";
}