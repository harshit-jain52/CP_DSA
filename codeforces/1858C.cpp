#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;

        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
                continue;

            int x = 1;
            while (i * x <= n)
            {
                v.push_back(i * x);
                x *= 2;
            }
        }

        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}