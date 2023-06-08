#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        unordered_map<char, int> m;
        char c;
        for (int i = 0; i < 4; i++)
        {
            cin >> c;
            m[c]++;
        }

        int num = m.size();

        if (num == 4 || num == 3)
        {
            cout << 4;
        }
        else if (num == 1)
        {
            cout << -1;
        }
        else
        {
            // num == 2
            int flag = 0;
            for (auto it : m)
            {
                if (it.second == 3)
                {
                    flag = 1;
                }
            }
            if (flag)
            {
                cout << 6;
            }
            else
            {
                cout << 4;
            }
        }
        cout << endl;
    }
}