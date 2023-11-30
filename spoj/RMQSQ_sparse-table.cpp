#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int LOG = 20;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m[n][LOG];
    for (int i = 0; i < n; i++)
    {
        m[i][0] = arr[i];
    }

    for (int pow = 1; (1 << pow) <= n; pow++)
    {
        for (int i = 0; i + (1 << pow) - 1 < n; i++)
        {
            m[i][pow] = min(m[i][pow - 1], m[i + (1 << (pow - 1))][pow - 1]);
        }
    }

    int log[n + 1];
    log[1] = 0;
    for (int i = 2; i <= n; i++)
        log[i] = log[i / 2] + 1;

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;

        int k = log[len];
        cout << min(m[l][k], m[r - (1 << k) + 1][k]) << endl;
    }
}

// O(NlogN) + O(Q)