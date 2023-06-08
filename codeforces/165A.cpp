#include <bits/stdc++.h>
using namespace std;

// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n, i, j, count = 0;
    cin >> n;
    vector<pair<int, int>> c(n);

    for (i = 0; i < n; i++)
    {
        cin >> c[i].first >> c[i].second;
    }

    int flag1, flag2, flag3, flag4;

    for (i = 0; i < n; i++)
    {
        flag1 = flag2 = flag3 = flag4 = 0;
        for (j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }

            if (c[j].first > c[i].first && c[j].second == c[i].second)
            {
                flag1 = 1;
            }
            else if (c[j].first < c[i].first && c[j].second == c[i].second)
            {
                flag2 = 1;
            }
            else if (c[j].first == c[i].first && c[j].second > c[i].second)
            {
                flag3 = 1;
            }
            else if (c[j].first == c[i].first && c[j].second < c[i].second)
            {
                flag4 = 1;
            }
        }
        if (flag1 && flag2 && flag3 && flag4)
        {
            count++;
        }
    }

    cout << count;
}