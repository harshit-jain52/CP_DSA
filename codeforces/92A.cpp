#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, temp;
    cin >> n >> m;

    while (1)
    {
        for (i = 1; i <= n; i++)
        {
            if (m < i)
            {
                goto end;
            }
            m -= i;
        }
    }

end:
    cout << m;
}