#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n + 1);
    h[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    while (m--)
    {
        int t;
        cin >> t;
        if (h.size() > 0)
        {
            auto it = upper_bound(h.begin(), h.end(), t);
            it--;
            cout << *it << endl;
            
            if (it != h.begin())
                h.erase(it);
        }
        else
        {
            cout << -1 << endl;
        }
    }
}