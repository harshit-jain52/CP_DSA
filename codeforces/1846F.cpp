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
        int occ[10] = {0};
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            occ[a[i]]++;
        }

        int tmp[10], whoChanged;

    again:
        cout << "- " << 0;
        cout << endl;
        cout.flush();

        for (int i = 0; i < 10; i++)
        {
            tmp[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            tmp[a[i]]++;
        }

        whoChanged = -1;

        for (int i = 1; i <= 9; i++)
        {
            if (tmp[i] == occ[i] + 1)
            {
                whoChanged = i;
                break;
            }
        }

        if (whoChanged == -1)
            goto again;

        cout << "- " << (n - tmp[whoChanged]) << " ";
        for (int i = 0; i < n; i++)
        {
            if (a[i] != whoChanged)
                cout << (i + 1) << " ";
        }
        cout << endl;
        cout.flush();

        n = tmp[whoChanged];

        while (1)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            for (int i = 0; i < n; i++)
            {
                if (a[i] != whoChanged)
                {
                    cout << "! " << (i + 1);
                    cout << endl;
                    cout.flush();
                    goto end;
                }
            }

            cout << "- " << 0;
            cout << endl;
            cout.flush();
        }
    end:
        cout << endl;
    }
}