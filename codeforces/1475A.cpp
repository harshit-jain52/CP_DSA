#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll check(ll num)
{
    if (num & 1)
    {
        return num;
    }
    else
    {
        return check(num / 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        if (check(n) != 1)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }
}