#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n], b[n];
        unordered_map<int, int> ma, mb;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int ct = 1;
        ma[a[0]] = 1;
        for (i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                ct++;
            }
            else
            {
                ct = 1;
            }
            ma[a[i]] = max(ma[a[i]], ct);
        }
        
        ct = 1;
        mb[b[0]] = 1;
        for (i = 1; i < n; i++)
        {
            if (b[i] == b[i - 1])
            {
                ct++;
            }
            else
            {
                ct = 1;
            }
            mb[b[i]] = max(mb[b[i]], ct);
        }

        int ans = 0;
        for (i = 1; i <= 2 * n; i++)
        {
            ans = max(ans, ma[i] + mb[i]);
        }
        cout << ans << endl;
    }
}