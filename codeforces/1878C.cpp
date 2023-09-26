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
        ll n, k;
        ll x;
        cin >> n >> k >> x;

        ll max = 0;
        ll min = 0;
        for (int i = 0; i < k; i++)
        {
            max += n - i;
            min += (i + 1);
        }

        if (x > max || x < min)
            cout << "NO";
        else
            cout << "YES";

        cout << endl;
    }
}