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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int l[k], r[k];

        for (int i = 0; i < k; i++)
        {
            cin >> l[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> r[i];
        }

        vector<int> marking(n + 1, 0);

        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            int idx = lower_bound(r, r + k, x) - r;
            int a = min(x, l[idx] + r[idx] - x);
            int b = max(x, l[idx] + r[idx] - x);

            marking[a - 1] += 1;
            marking[b] -= 1;
        }

        for (int i = 1; i < n; i++)
        {
            marking[i] += marking[i - 1];
        }

        for (int idx = 0; idx < k; idx++)
        {
            int lo = l[idx] - 1, hi = r[idx] - 1;

            while (lo < hi)
            {
                if (marking[lo] % 2 != 0)
                {
                    swap(s[lo], s[hi]);
                }
                lo++;
                hi--;
            }
        }

        cout << s << endl;
    }
}