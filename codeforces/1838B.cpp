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
        int p[n], idx1, idx2, idxn;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            if (p[i] == 1)
                idx1 = i;
            else if (p[i] == 2)
                idx2 = i;
            else if (p[i] == n)
                idxn = i;
        }

        if (idxn < idx2)
        {
            if (idx1 < idx2)
            {
                if (idx1 < idxn)
                    cout << idx1 << " " << idx1;
                else
                    cout << idx1 << " " << idxn;
            }
            else
                cout << idx2 << " " << idxn;
        }
        else
        {
            if (idx1 > idx2)
            {
                if (idx1 > idxn)
                    cout << idx1 << " " << idx1;
                else
                    cout << idx1 << " " << idxn;
            }
            else
                cout << idx2 << " " << idxn;
        }

        cout << endl;
    }
}