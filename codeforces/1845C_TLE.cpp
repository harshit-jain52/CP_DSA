#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 3e5 + 5;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, l, r;
        int m, n;
        cin >> s;
        cin >> m;
        cin >> l >> r;
        n = s.size();

        vector<vector<int>> indices(10);
        for (int i = 0; i < n; i++)
        {
            indices[s[i] - '0'].push_back(i);
        }

        set<string> allCombinations;
        for (char c = l[0]; c <= r[0]; c++)
        {
            string str = "";
            str.push_back(c);
            allCombinations.insert(str);
        }
        for (int i = 1; i < m; i++)
        {
            set<string> tmpCombinations;
            for (auto it : allCombinations)
            {
                for (char c = l[i]; c <= r[i]; c++)
                {
                    string str = it;
                    str.push_back(c);
                    tmpCombinations.insert(str);
                }
            }
            allCombinations = tmpCombinations;
            tmpCombinations.clear();
        }

        bool ans = false;
        for (auto str : allCombinations)
        {
            int idx = -1;
            for (char c : str)
            {
                auto it = upper_bound(indices[c - '0'].begin(), indices[c - '0'].end(), idx);
                if (it == indices[c - '0'].end())
                {
                    ans = true;
                    break;
                }
                else
                {
                    idx = *it;
                }
            }
            if (ans)
                break;
        }

        if (ans)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}