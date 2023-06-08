/*
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int i;
        long long temp, candies = 0;
        multiset<long long> bags;

        for (i = 0; i < n; i++)
        {
            cin >> temp;
            bags.insert(temp);
        }

        while (k--)
        {
            auto it = --bags.end();
            candies += (*it);
            bags.insert((*it) / 2);
            bags.erase(it);
        }
        cout << candies << endl;
    }
}