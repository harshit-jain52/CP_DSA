#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n], i;
    map<int, int> m;

    for (i = 0; i < n; i++)
    {
        cin >> p[i];
        m[p[i]] = i + 1;
    }

    for (auto it : m)
    {
        cout << it.second << " ";
    }
}