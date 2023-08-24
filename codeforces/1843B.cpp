#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += abs(a[i]);
        }

        bool searching = false;
        int op = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0 && !searching)
            {
                searching = true;
                op++;
            }

            if (a[i] > 0 && searching)
                searching = false;
        }

        cout << sum << " " << op << endl;
    }
}