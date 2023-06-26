#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l[n];
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }
        sort(l, l + n);
        int liars;
        bool possible = false;
        for (liars = l[0]; liars <= n; liars++)
        {
            if (l[n - 1 - liars] <= liars && (liars == 0 || l[n - liars] > liars))
            {
                possible = true;
                break;
            }
        }
        if (possible)
            cout << liars;
        else
            cout << -1;

        cout << endl;
    }
}