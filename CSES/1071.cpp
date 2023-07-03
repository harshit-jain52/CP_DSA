#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll y, x;
        cin >> y >> x;
        ll num = max(y, x);

        if (num % 2 == 0)
        {
            if (y == num)
                cout << num * num + 1 - x;
            else
                cout << (num - 1) * (num - 1) + y;
        }
        else
        {
            if (x == num)
                cout << num * num + 1 - y;
            else
                cout << (num - 1) * (num - 1) + x;
        }
        cout << endl;
    }
}