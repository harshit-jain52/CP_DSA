#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        ll q;
        cin >> n >> k >> q;
        int ct = 0;
        vector<int> consec;
        for (int i = 0; i < n; i++)
        {
            ll tmp;
            cin >> tmp;

            if (tmp <= q)
                ct++;
            else
            {
                consec.push_back(ct);
                ct = 0;
            }
        }
        consec.push_back(ct);

        /*
        if num_of_days>=k
        num_of_ways = (n-k+1) + (n-k) + (n-k-1) + ... (n-k - (n-k))
        = (n-k)*(n-k+2) - (n-k)(n-k+1)/2 + 1
        */

        ll ans = 0;
        for (auto it : consec)
        {
            if (it >= k)
            {
                ll diff = it - k;
                ans += (diff * (diff + 2) - diff * (diff + 1) / 2 + 1);
            }
        }
        cout << ans << endl;
    }
}