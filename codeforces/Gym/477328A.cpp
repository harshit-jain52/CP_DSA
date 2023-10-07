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
        int n, m;
        cin >> n >> m;

        ll arr[n + 1] = {0};

        int i = 0;
        while (m--)
        {
            int idx;
            ll val;

            cin >> idx >> val;

            if (val > 0)
                arr[i + 1] += val;
            else
                arr[idx] += val;

            i++;
            i %= n;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
}