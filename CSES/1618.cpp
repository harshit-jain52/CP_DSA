#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    ll n, num = 5;
    cin >> n;
    int ct = 0;

    while (num <= n)
    {
        ct += n / num;
        num *= 5;
    }

    cout << ct;
}