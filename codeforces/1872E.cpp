#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        ll prefixXOR[n + 1];
        prefixXOR[0] = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            prefixXOR[i + 1] = prefixXOR[i] ^ a[i];
        }

        string s;
        cin >> s;
        ll XOR1 = 0, XOR0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                XOR1 ^= a[i];
            else
                XOR0 ^= a[i];
        }

        int q;
        cin >> q;
        while (q--)
        {
            int tp;
            cin >> tp;

            if (tp == 1)
            {
                int l, r;
                cin >> l >> r;

                ll changeXOR = prefixXOR[r] ^ prefixXOR[l - 1];
                XOR1 ^= changeXOR;
                XOR0 ^= changeXOR;
            }
            else
            {
                int g;
                cin >> g;
                if (g == 0)
                    cout << XOR0 << " ";
                else
                    cout << XOR1 << " ";
            }
        }
        cout << endl;
    }
}