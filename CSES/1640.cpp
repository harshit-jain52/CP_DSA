#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n, x;
    cin >> n >> x;
    map<int, vector<int>> m;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        m[tmp].push_back(i+1);
    }

    bool possible = false;
    for (auto it : m)
    {
        if (2 * it.first == x)
        {
            if (it.second.size() != 1)
            {
                cout << it.second[0] << " " << it.second[1];
                possible = true;
                break;
            }
        }

        else if (m.find(x - it.first) != m.end())
        {
            cout << it.second[0] << " " << m[x - it.first][0];
            possible = true;
            break;
        }
    }

    if (!possible)
        cout << "IMPOSSIBLE";
}