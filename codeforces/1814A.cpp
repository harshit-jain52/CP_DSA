#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        if (n % 2 == 1 && k % 2 == 0)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        cout << '\n';
    }
}