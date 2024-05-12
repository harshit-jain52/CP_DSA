#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    ll ct = 0;
    for (ll num = 2; num * num <= 2 * N; num++)
    {
        if ((2 * N) % num)
            continue;
        ll div = (2 * N) / num; // num+2l-1
        ll diff = div - (num - 1);
        if (diff > 0 && diff % 2 == 0)
            ct++;
    }
    cout << ct;
}