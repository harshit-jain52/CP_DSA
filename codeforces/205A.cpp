#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    lli min = 1e9+1, temp;
    int num, occ, n, i;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp < min)
        {
            min = temp;
            num = i + 1;
            occ = 1;
        }
        else if (temp == min)
        {
            occ++;
        }
    }

    if (occ == 1)
    {
        cout << num;
    }
    else
    {
        cout << "Still Rozdil";
    }

    return 0;
}