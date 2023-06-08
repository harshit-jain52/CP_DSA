#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;

    cin >> n;
    int a[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m;
    int b[m];

    for (j = 0; j < m; j++)
    {
        cin >> b[j];
    }

    vector<int> gears;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (b[j] % a[i] == 0)
            {
                gears.push_back(b[j] / a[i]);
            }
        }
    }

    cout << count(gears.begin(), gears.end(), *max_element(gears.begin(), gears.end()));
}