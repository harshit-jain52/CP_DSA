#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// void printMap(map<ll, int> m)
// {
//     for (auto it : m)
//     {
//         cout << it.first << " " << it.second << endl;
//     }
//     cout << endl;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, i, miss;
        ll c, d, temp, cost = 0, a, num;
        cin >> n >> c >> d;
        map<ll, int> ct, ms;

        for (i = 0; i < n; i++)
        {
            cin >> a;
            ct[a]++;
        }

        // printMap(ct);

        //  remove duplicates
        for (auto it : ct)
        {
            if (it.second > 1)
            {
                cost += (it.second - 1) * c;
                ct[it.first] = 1;
            }
        }

        // add 1 if not there
        auto j = ct.begin();
        if ((*j).first != 1)
        {
            cost += d;
            ct[1] = 1;
        }

        // printMap(ct);

        // missing count
        num = 1, miss = 0;
        for (auto it : ct)
        {
            if (it.first == num)
            {
                num++;
            }
            else
            {
                miss += it.first - num;
                num = it.first + 1;
            }
            ms[it.first] = miss;
        }

        // printMap(ms);

        j = --ct.end();
        while (ms[(*j).first] != 0)
        {
            if (j == ct.begin())
            {
                if (d * ms[(*j).first] < c || ms[(*j).first] < 2)
                {
                    cost += d * ms[(*j).first];
                }
                else
                {
                    cost += (c + d);
                }
                break;
            }
            else
            {
                if (d * ms[(*j).first] < c)
                {
                    cost += d * ms[(*j).first];
                    break;
                }
                else
                {
                    cost += c;
                    j--;
                }
            }
        }

        cout << cost << endl;
    }
}