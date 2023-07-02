#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;

        cout << n << " ";
    }
}