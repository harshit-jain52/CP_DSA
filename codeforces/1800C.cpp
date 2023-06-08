#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long cards[n], power = 0;
        multiset<long long> bonus;
        int i;

        for (i = 0; i < n; i++)
        {
            cin >> cards[i];
        }
        for (i = 0; i < n; i++)
        {
            if (cards[i] > 0)
            {
                bonus.insert(cards[i]);
            }
            else
            {
                if (bonus.size() > 0)
                {
                    auto it = bonus.end();
                    it--;
                    power += (*it);
                    bonus.erase(it);
                }
            }
        }
        cout << power << endl;
    }
}