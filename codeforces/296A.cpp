#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, i, maxcount = 0;
    cin >> n;

    int a[n];
    set<int> s;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    for (auto j : s)
    {
        maxcount = max(maxcount, count(a, a + n, j));
    }

    if (maxcount <= n / 2 + n % 2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}