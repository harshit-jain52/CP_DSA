#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int diff = n - 10;
    switch (diff)
    {
    case 1 ... 9:
        cout << 4;
        break;

    case 10:
        cout << 15;
        break;

    case 11:
        cout << 4;
        break;

    default:
        cout << 0;
        break;
    }
}