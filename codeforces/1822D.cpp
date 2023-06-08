#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            if (n % 2 == 1)
            {
                cout << -1 << endl;
            }
            else
            {
                int num1 = n - 1, num2 = 2, i;
                cout << n << " ";

                for (i = 0; i < n - 2; i++)
                {
                    if (i % 2 == 0)
                    {
                        cout << num1;
                        num1 -= 2;
                    }
                    else
                    {
                        cout << num2;
                        num2 += 2;
                    }
                    cout << " ";
                }
                cout << 1 << endl;
            }
        }
    }
}