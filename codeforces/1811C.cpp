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
        int b[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        cout << b[0] << " ";
        for (int i = 0; i < n - 2; i++)
        {
            cout << min(b[i], b[i + 1]) << " ";
        }
        cout << b[n - 2] << endl;
    }
}