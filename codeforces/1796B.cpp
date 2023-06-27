#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();

        if (a[0] == b[0])
        {
            cout << "YES" << endl;
            cout << a[0] << '*' << endl;
        }
        else if (a[n - 1] == b[m - 1])
        {
            cout << "YES" << endl;
            cout << '*' << a[n - 1] << endl;
        }
        else
        {
            string tmp = "";
            bool possible = false;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < m - 1; j++)
                {
                    if (a[i] == b[j] && a[i + 1] == b[j + 1])
                    {
                        tmp.push_back(a[i]);
                        tmp.push_back(a[i + 1]);
                        possible = true;
                        goto end;
                    }
                }
            }
        end:
            if (possible)
            {
                cout << "YES" << endl;
                cout << '*' << tmp << '*' << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}