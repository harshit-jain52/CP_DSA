#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k, l, i;
    int flag = 0, count = 0;
    cin >> k >> l;

    for (i = k; i <= l; i *= k)
    {
        if (i == l)
        {
            flag = 1;
            break;
        }
        count++;
    }
    if (flag)
    {
        cout << "YES" << endl
             << count;
    }
    else
    {
        cout << "NO";
    }
}