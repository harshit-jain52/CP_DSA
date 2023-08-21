#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

int combination(int p, int q)
{
    int ans = 1;
    int num = 1;

    while (num <= q)
    {
        ans = (ans * 1LL * (p - num + 1)) % M;
        ans = (ans * 1LL * binExp(num, M - 2)) % M;
        num++;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        map<int, int> ct, ct_in_k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ct[a[i]]++;
        }

        sort(a, a + n);

        for (int i = n - 1; i >= n - k; i--)
        {
            ct_in_k[a[i]]++;
        }

        // last element
        int p = ct[a[n - k]], q = ct_in_k[a[n - k]];
        // cout << p << " " << q << " ";

        // find pCq
        cout << combination(p, min(q, p - q)) << endl;
    }
}