#include <bits/stdc++.h>
using namespace std;

int main()
{
    int lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    int n, flag = 0;
    cin >> n;

    for (auto it : lucky)
    {
        if (n % it == 0 && n >= it)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}