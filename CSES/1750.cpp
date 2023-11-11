#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    int t[n+1][31];
    
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i][0];
    }

    int pow = 1;
    while (pow <= 30)
    {
        for (int i = 1; i <= n; i++)
            t[i][pow] = t[t[i][pow - 1]][pow - 1];
        pow++;
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;

        int ans = x;
        for (int pow = 0; pow <= 30; pow++)
        {
            if (k & (1 << pow))
            {
                ans = t[ans][pow];
            }
        }

        cout << ans << endl;
    }
}