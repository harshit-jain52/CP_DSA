#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll num = 1e5;

    for (int i = 0; i < n; i++)
    {
        cout << (num + i) << " ";
    }
}