#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, l, i;
    cin >> n >> m;
    int a[n], num[n];
    unordered_set<int> dist;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = n - 1; i >= 0; i--)
    {
        dist.insert(a[i]);
        num[i] = dist.size();
    }

    while (m--)
    {
        cin >> l;
        cout << num[l - 1] << endl;
    }
}