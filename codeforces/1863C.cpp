#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        ll req = n * 1LL * (n + 1) / 2, sum = 0;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        v.push_back(req - sum);

        // for (auto it : v)
        // {
        //     cout << it << " ";
        // }

        int start = n + 1 - k % (n + 1);

        for (int i = start, ct = 0; ct < n; i++, ct++)
        {
            if (i > n)
                i = i % (n + 1);

            cout << v[i] << " ";
        }

        cout << endl;
    }
}