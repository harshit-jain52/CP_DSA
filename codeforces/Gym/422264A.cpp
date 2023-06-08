#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = sqrt(1e9);

int main()
{
    int p[N + 1];
    for (int i = 0; i <= sqrt(1e9); i++)
    {
        p[i] = i * i;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (upper_bound(p, p + N + 1, r) - lower_bound(p, p + N + 1, l)) << endl;
    }
}