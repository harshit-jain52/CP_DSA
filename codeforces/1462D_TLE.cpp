#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> p;

bool allSame(vector<int> &v)
{
    int x = 0, i;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            x = v[i];
            break;
        }
    }
    if (x == 0)
    {
        return false;
    }

    for (i = 0; i < v.size(); i++)
    {
        if (v[i] != x && v[i] != 0)
        {
            return false;
        }
    }
    return true;
}

void generate(vector<int> &a, int i)
{
    if (allSame(a))
    {
        p.push_back(a);
        return;
    }
    if (i == a.size() - 1)
    {
        return;
    }

    int temp = a[i];
    a[i + 1] += temp;
    a[i] = 0;
    generate(a, i + 1);
    a[i] = temp;
    a[i + 1] -= temp;
    generate(a, i + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, temp;
        cin >> n;
        vector<int> a;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        generate(a, 0);

        int ct, maxct = 0;
        for (auto it : p)
        {
            ct = 0;
            for (auto j : it)
            {
                if (j != 0)
                {
                    ct++;
                }
            }
            if (ct > maxct)
            {
                maxct = ct;
            }
        }

        cout << (n - maxct) << endl;
        p.clear();
    }
}