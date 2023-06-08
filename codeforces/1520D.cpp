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
        // aj - ai = j - i  --> aj - j = ai - i

        int n;
        cin >> n;
        int a[n], i;
        ll ct = 0;
        unordered_map<int, ll> m;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (i = 0; i < n; i++)
        {
            ct += m[a[i] - i];
            m[a[i] - i]++; // marking
        }

        cout << ct << endl;
    }
}