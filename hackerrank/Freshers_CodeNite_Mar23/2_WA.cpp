#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i, num;
        cin >> n >> k;

        vector<ll> before;
        vector<ll> a;
        ll min, temp;

        for (i = 0; i < k - 1; i++)
        {
            cin >> temp;
            temp = temp / 2 + (int)(temp % 2 == 1);
            before.push_back(temp);
        }
        for (; i < n; i++)
        {
            cin >> temp;
            temp = temp / 2 + (int)(temp % 2 == 1);
            a.push_back(temp);
        }

        for (auto it : before)
        {
            a.push_back(it);
        }

        min = a[0];
        num = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
                num = i;
            }
        }

        cout << abs(k - num) << endl;
    }
}