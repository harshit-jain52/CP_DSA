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
        int n, k;
        cin >> n >> k;
        int p[n], i;

        for (i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        int num = 1, cnt = 0;

        for (i = 0; i < n; i++)
        {
            if (p[i] != num)
            {
                cnt++;
            }
            else
            {
                num++;
            }
        }

        cout << cnt / k + (int)(cnt % k != 0) << endl;
    }
}