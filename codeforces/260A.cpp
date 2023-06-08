#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, n, i, result;
    string res;
    cin >> a >> b >> n;

    result = a * 10;
    for (i = 0; i < 10; i++)
    {
        if ((result + i) % b == 0)
        {
            result += i;
            break;
        }
    }

    if (i == 10)
    {
        cout << -1;
    }
    else
    {
        res = to_string(result);

        for (i = 1; i < n; i++)
        {
            res.push_back('0');
        }
        cout << res;
    }
}