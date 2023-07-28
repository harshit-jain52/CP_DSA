#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool solve()
{
    int n, k;
    cin >> n >> k;
    int c[n];

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int leftidx = -1, rightidx = -1;

    int tmpct = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == c[0])
        {
            tmpct++;
        }
        if (tmpct == k)
        {
            leftidx = i;
            break;
        }
    }
    if (leftidx == -1)
        return false;

    if (c[0] == c[n - 1])
        return true;

    tmpct = 0;
    for (int i = n - 1; i > leftidx; i--)
    {
        if (c[i] == c[n - 1])
        {
            tmpct++;
        }
        if (tmpct == k)
        {
            rightidx = i;
            break;
        }
    }

    if (rightidx == -1)
        return false;

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}