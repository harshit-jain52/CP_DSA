#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int maxgo = 1e9;

        while (n--)
        {
            int d, s;
            cin >> d >> s;

            maxgo = min(maxgo, d + s / 2 - (s % 2 == 0));
        }

        cout << maxgo << endl;
    }
}