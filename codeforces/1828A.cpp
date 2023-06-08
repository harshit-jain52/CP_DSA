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
        int a[n], sum = 0;
        for (int i = 1; i < n; i++)
        {
            a[i] = i + 1;
            sum += a[i];
        }

        a[0] = n - sum % n;

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}