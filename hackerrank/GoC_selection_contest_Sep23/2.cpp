#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<multiset<int>> v(n);
        while (q--)
        {
            int type;
            cin >> type;

            if (type == 1)
            {
                int i;
                int x;
                cin >> i >> x;
                v[i - 1].insert(x);
            }
            else
            {
                int i;
                cin >> i;

                if (v[i - 1].size() == 0)
                    cout << -1 << " ";
                else
                {
                    auto it = --v[i - 1].end();
                    cout << *it << " ";
                    v[i - 1].erase(it);
                }
            }
        }
        cout << endl;
    }
}