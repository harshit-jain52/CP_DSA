#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        int maxlen = 1, tmplen = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] <= k)
                tmplen++;
            else
                tmplen = 1;

            maxlen = max(maxlen, tmplen);
        }

        cout << (n - maxlen) << endl;
    }
}