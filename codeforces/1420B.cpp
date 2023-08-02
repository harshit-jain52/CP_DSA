#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int highestSetBit(int n)
{
    int ans = 0;
    for (int i = 0; i <= 30; i++)
    {
        if ((n >> i) & 1)
            ans = i;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> ct(31, 0);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            ct[highestSetBit(a)]++;
        }

        ll count = 0;
        for (int i = 0; i < 31; i++)
        {
            count += (ct[i] * (ct[i] - 1)) / 2; // nC2
        }

        cout << count << endl;
    }
}