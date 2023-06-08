#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, c1, c2;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        switch (n % 3)
        {
        case 0:
            c1 = c2 = n / 3;
            break;
        case 1:
            c2 = n / 3;
            c1 = n / 3 + 1;
            break;
        case 2:
            c1 = n / 3;
            c2 = n / 3 + 1;
            break;
        }

        cout << c1 << " " << c2;
        cout << "\n";
    }

    return 0;
}