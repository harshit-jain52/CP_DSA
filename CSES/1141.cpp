#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    int tmpcount = 0, maxcount = 0, k[n], start = 0;
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (m.find(k[i]) == m.end() || m[k[i]] < start)
        {
            m[k[i]] = i;
            tmpcount++;
        }
        else
        {
            start=m[k[i]]+1;
            m[k[i]] = i;
            tmpcount = i - start + 1;
        }
        maxcount = max(maxcount, tmpcount);
    }

    cout << maxcount;
}