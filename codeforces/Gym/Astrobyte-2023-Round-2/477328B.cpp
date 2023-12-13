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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        int store[n];
        int lastRight = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')
                lastRight = i;
            else
                store[i] = lastRight;
        }

        int nextleft = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'L')
                nextleft = i;
            else
                store[i] = nextleft;
        }

        for (int i = 0; i < n; i++)
        {
            int x = abs(store[i] - i);
            if (x % 2 == 1)
            {
                if (s[i] == 'L')
                    store[i]++;
                else
                    store[i]--;
            }
        }

        int range[n] = {0};
        for (int i = 0; i < n; i++)
        {
            range[store[i]]++;
        }

        int sum[n + 1];
        sum[0] = 0;
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + range[i];
        }

        while (q--)
        {
            int type;
            cin >> type;

            if (type == 1)
            {
                int idx;
                cin >> idx;
                cout << store[idx - 1] + 1 << endl;
            }
            else
            {
                int l, r;
                cin >> l >> r;
                cout << sum[r] - sum[l - 1] << endl;
            }
        }
    }
}