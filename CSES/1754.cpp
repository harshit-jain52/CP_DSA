#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (a < b)
            swap(a, b);

        if (a > 2 * b)
        {
            cout << "NO" << endl;
            continue;
        }
        if ((a % 3 + b % 3) % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}