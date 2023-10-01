#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> h;

    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        h.insert(tmp);
    }

    while (m--)
    {
        int t;
        cin >> t;
        if (h.size() > 0)
        {
            auto it = h.upper_bound(t);
            if (it == h.begin())
                cout << -1 << endl;
            else
            {
                it--;
                cout << *it << endl;
                h.erase(it);
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
}