#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = ((ans % M) * (2)) % M;
    }

    cout << ans;
}