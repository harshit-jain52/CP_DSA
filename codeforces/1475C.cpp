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
        int a, b, k, i;
        cin >> a >> b >> k;
        int boys[k], girls[k];
        unordered_map<int, int> boyct, girlct;
        for (i = 0; i < k; i++)
        {
            cin >> boys[i];
            boyct[boys[i]]++;
        }
        for (i = 0; i < k; i++)
        {
            cin >> girls[i];
            girlct[girls[i]]++;
        }

        ll tot = 0;
        for (i = 0; i < k; i++)
        {
            tot += k - boyct[boys[i]] - girlct[girls[i]] + 1;
        }
        cout << tot/2 << endl;
    }
}