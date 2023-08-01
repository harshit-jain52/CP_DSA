#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int generateX(int k, int a, int b)
{
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        int abit = (a >> i) & 1;
        int bbit = (b >> i) & 1;

        if (abit == 0 && bbit == 0)
        {
            x = x | (1 << i);
        }
    }

    return x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            v[i] = {tmp, i+1};
        }

        sort(v.begin(), v.end());
        int maxval = -1, idx1 = -1, idx2 = -1, xans = -1;

        for (int i = 1; i < n; i++)
        {
            int a = v[i].first, b = v[i - 1].first;
            int x = generateX(k, a, b);
            int val = ((a ^ x) & (b ^ x));
            if (val > maxval)
            {
                idx1 = v[i].second;
                idx2 = v[i - 1].second;
                xans = x;
                maxval = val;
            }
        }

        cout << idx1 << " " << idx2 << " " << xans << endl;
    }
}