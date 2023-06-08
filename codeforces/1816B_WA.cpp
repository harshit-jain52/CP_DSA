#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[2][n], i, j, num1 = 1, num2 = 2 * n;

        for (i = 1; i <= 2; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    cout << num2 << " ";
                    num2--;
                }
                else
                {
                    cout << num1 << " ";
                    num1++;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}