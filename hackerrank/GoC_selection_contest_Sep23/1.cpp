#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
    ll n;
    cin >> n;
    for (int i = 0; i <= 60; i++)
    {
        if ((1LL << i) == n)
            return false;
        if ((1LL << i) > n)
            break;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
}