#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, count = 0;
    cin >> n;
    vector<int> a(n);

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++)
    {
        if (find(a.begin(), a.end(), i) == a.end())
        {
            count++;
        }
    }

    cout << count;
}