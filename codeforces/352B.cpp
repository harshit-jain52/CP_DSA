#include <bits/stdc++.h>
using namespace std;

int isAP(vector<int> v)
{
    if (v.size() == 1)
    {
        return 0;
    }
    else
    {
        int diff = v[1] - v[0], i;
        for (i = 1; i < v.size(); i++)
        {
            if (v[i] - v[i - 1] != diff)
            {
                break;
            }
        }
        if (i == v.size())
        {
            return diff;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n], i, d, count = 0;
    map<int, vector<int>> data;
    vector<pair<int, int>> x;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        data[a[i]].push_back(i);
    }

    for (auto it : data)
    {
        d = isAP(it.second);

        if (d != -1)
        {
            count++;
            x.push_back({it.first, d});
        }
    }

    cout << count << endl;
    for (i = 0; i < count; i++)
    {
        cout << x[i].first << " " << x[i].second << endl;
    }
}