#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, s, r, sum;
    cin >> t;

    while (t--)
    {
        cin >> n >> s >> r;

        if (n == 1)
        {
            cout << s;
        }
        else
        {
            vector<int> v(n - 1, 1);
            sum = n - 1;
            int i = 0;

            while (sum != r)
            {
                v[i]++;
                sum++;

                i++;
                if (i == n - 1)
                    i = 0;
            }

            cout << s - r << " ";
            for (auto it : v)
            {
                cout << it << " ";
            }
        }

        cout << endl;
    }
}