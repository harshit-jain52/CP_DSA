/*
https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            int num = 0;

            string s;
            cin >> s;
            int sz = s.size();

            for (int j = 0; j < sz; j++)
            {
                for (int c = 0; c < 5; c++)
                {
                    if (s[j] == vowels[c])
                        num |= (1 << c);
                }
            }

            v[i] = num;
        }

        ll ways = 0;
        for (int num = 1; num < 32; num++)
        {
            int set_bits = __builtin_popcount(num);

            ll ct = 0;
            for (int i = 0; i < n; i++)
            {
                if ((v[i] & num) == num)
                    ct++;
            }

            if (set_bits & 1)
            {
                ways += ct * (ct - 1) * (ct - 2) / 6;
            }
            else
            {
                ways -= ct * (ct - 1) * (ct - 2) / 6;
            }
        }

        cout << ways << endl;
    }
}