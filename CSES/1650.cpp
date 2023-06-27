#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n], prefix_xor[n + 1];
    prefix_xor[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefix_xor[i + 1] = (prefix_xor[i] ^ a[i]);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (prefix_xor[l - 1] ^ prefix_xor[r]) << endl;
    }
}