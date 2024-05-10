#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    ll l;
    cin >> n >> k >> l;
    int ct = 0, currsize = 0, currmin;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (currsize == 0)
        {
            currmin = tmp;
            currsize = 1;
        }
        else
        {
            if (tmp - currmin > l)
            {
                ct++;
                currmin = tmp;
                currsize = 1;
            }
            else
            {
                currsize++;
            }
        }
        if (currsize == k)
        {
            ct++;
            currsize = 0;
        }
    }

    if (currsize)
        ct++;

    cout << ct;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}