#include <bits/stdc++.h>
using namespace std;

int main()
{
    long i, t, sx, sy, ex, ey;
    cin >> t >> sx >> sy >> ex >> ey;

    char dir[t];

    for (i = 0; i < t; i++)
    {
        cin >> dir[i];
    }

    i = 0;
    while (!(sx == ex && sy == ey) && i < t)
    {
        if (ex > sx && dir[i] == 'E')
        {
            sx++;
        }
        else if (ex < sx && dir[i] == 'W')
        {
            sx--;
        }
        else if (ey > sy && dir[i] == 'N')
        {
            sy++;
        }
        else if (ey < sy && dir[i] == 'S')
        {
            sy--;
        }

        i++;
    }

    if (sx == ex && sy == ey)
    {
        cout << i;
    }
    else
    {
        cout << -1;
    }
}