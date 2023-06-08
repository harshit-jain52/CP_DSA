#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    any such number would be made up of 11 and/or 111, all other 11111.. are made up of these only
    num = 11x + 111y = 11x + 111(11i + r) = 11a + 111r where 0<=r<=10
    */
    int t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        int i = 0;
        bool ans = false;
        while (x >= 0 && i < 11)
        {
            if (x % 11 == 0)
            {
                ans = true;
                break;
            }
            x -= 111;
            i++;
        }

        if (ans)
            cout << "YES";
        else
            cout << "NO";
        
        cout << endl;
    }
}