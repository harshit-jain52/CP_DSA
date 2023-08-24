#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
    int n;
    cin >> n;

    int a[n];
    map<int, int> ct;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ct[a[i]]++;
    }

    if (a[0] != n)
        return false;
    if (ct[a[0]] != a[n - 1])
        return false;

    for (int i = n - 1; i > 0; i--)
    {
        if (a[i - 1] > a[i])
        {
            if (a[i - 1] - a[i] != ct[a[i]])
                return false;
        }
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}