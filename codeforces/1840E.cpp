#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size(), unmatched = 0;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
                unmatched++;
        }

        int t, q;
        cin >> t >> q;
        int blocked = 0;
        vector<int> times;

        for (int j = 1; j <= q; j++)
        {
            auto it = lower_bound(times.begin(), times.end(), j);
            if (it != times.end())
            {
                if (*it == j)
                    blocked--;
            }

            int choice;
            cin >> choice;

            if (choice == 1)
            {
                int pos;
                cin >> pos;
                if (s1[pos - 1] != s2[pos - 1])
                {
                    blocked++;
                    times.push_back(j + t);
                }
            }
            else if (choice == 2)
            {
                int p, pos1, q, pos2;
                cin >> p >> pos1 >> q >> pos2;
                if (s1[pos1 - 1] == s2[pos1 - 1])
                    unmatched++;
                if (s1[pos2 - 1] == s2[pos2 - 1])
                    unmatched++;

                if (p == 1 && q == 1)
                    swap(s1[pos1 - 1], s1[pos2 - 1]);
                else if (p == 1 && q == 2)
                    swap(s1[pos1 - 1], s2[pos2 - 1]);
                else if (p == 2 && q == 1)
                    swap(s2[pos1 - 1], s1[pos2 - 1]);
                else
                    swap(s2[pos1 - 1], s2[pos2 - 1]);

                if (s1[pos1 - 1] == s2[pos1 - 1])
                    unmatched--;
                if (s1[pos2 - 1] == s2[pos2 - 1])
                    unmatched--;
            }
            else
            {
                if (blocked == unmatched)
                    cout << "YES";
                else
                    cout << "NO";
                cout << endl;
            }
        }
    }
}