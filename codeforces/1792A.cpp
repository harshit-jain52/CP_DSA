#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int count = 0, temp;
        multiset<int> health;

        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            health.insert(temp);
        }

        while (*(health.begin()) == 1 && health.size() > 1)
        {
            count++;
            auto it = health.begin();
            int temp1 = *it, temp2 = *(++it);
            it--;
            health.erase(health.begin());
            health.erase(health.begin());
            health.insert(temp1 - 1);
            health.insert(temp2 - 1);
            health.erase(0);
        }
        count += health.size();

        cout << count << endl;
    }
}