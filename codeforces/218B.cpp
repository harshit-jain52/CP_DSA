#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, count, max_zlotys = 0, min_zlotys = 0, temp;
    cin >> n >> m;
    int a[m], b[m], i;

    for (i = 0; i < m; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(a, a + m, greater<int>());
    count = 0;
    while (count < n)
    {
        temp = a[0];
        for (i = 0; i < m; i++)
        {
            if (a[i] == temp)
            {
                max_zlotys += a[i];
                a[i]--;
                count++;
                if (count == n)
                {
                    break;
                }
            }
            else if (a[i] < temp)
            {
                i = 0;
                break;
            }
        }
    }

    sort(b, b + m);
    i = 0;
    count = 0;

    while (count < n)
    {
        min_zlotys += b[i];
        b[i]--;
        count++;

        if (b[i] == 0)
        {
            i++;
        }
    }

    cout << max_zlotys << " " << min_zlotys;
}