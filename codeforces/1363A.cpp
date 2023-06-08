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
        int n, x, oddct = 0, evenct = 0, totsum = 0, i;
        cin >> n >> x;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
            {
                oddct++;
            }
            else
            {
                evenct++;
            }
            totsum += a[i];
        }
        if (x == n)
        {
            if (totsum % 2 == 1)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
        }
        else
        {
            if (x & 1)
            {
                if (oddct > 0)
                {
                    cout << "Yes";
                }
                else
                {
                    cout << "No";
                }
            }
            else
            {
                if (oddct > 0 && evenct > 0)
                {
                    cout << "Yes";
                }
                else
                {
                    cout << "No";
                }
            }
        }
        cout << endl;
    }
}