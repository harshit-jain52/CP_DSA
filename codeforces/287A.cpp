#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[4][4], i, j;
    char c;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cin >> c;
            a[i][j] = (c == '#') ? 1 : 0;
        }
    }

    vector<int> v;

    for (i = 1; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int sum = 0;
            sum = a[i][j] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j + 1];
            v.push_back(sum);
        }
    }

    int flag = 0;
    for (auto it : v)
    {
        if (it != 2)
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