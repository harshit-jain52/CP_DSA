#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n], i, j, m;
    vector<int> v;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    m = max_element(a, a + n) - a;

    int cntmax = 0;

    for (i = m; i < n; i++)
    {
        if (a[i] == a[m])
        {
            cntmax++;
        }
        else
        {
            break;
        }
    }

    for (i = m + 1, j = 0; j < n; j++, i++)
    {
        if (i == n)
        {
            i = 0;
        }
        v.push_back(a[i]);
    }
    int flag = 1;
    for (i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        cout << n - (m + 1) - (cntmax - 1);
    }
    else
    {
        cout << -1;
    }
}
