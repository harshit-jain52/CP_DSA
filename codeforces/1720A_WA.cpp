#include <bits/stdc++.h>
using namespace std;

long int lcm(long int x, long int y)
{
    long int res = (x > y) ? x : y;
    int i = res;

    while (1)
    {
        if (res % x == 0 && res % y == 0)
        {
            return res;
        }

        res += i;
    }
}

void simple(long int *x, long int *y)
{
    for (int i = 2; i <= *x; i++)
    {
        if (*x % i == 0 && *y % i == 0)
        {
            *x /= i;
            *y /= i;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    long int a, b, c, d;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c >> d;

        if (a == 0 && c == 0)
        {
            cout << 0 << endl;
        }
        else if (a == 0 || c == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            simple(&a, &b);
            simple(&c, &d);
            long int temp;

            if (a == c && b == d)
            {
                cout << 0 << endl;
            }

            else if (a == c)
            {
                temp = lcm(b, d);
                if (temp == b || temp == d)
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << 2;
                }
            }
            else if (b == d)
            {
                temp = lcm(a, c);
                if (temp == a || temp == c)
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << 2;
                }
            }
            else
            {
                
            }
        }
    }

    return 0;
}