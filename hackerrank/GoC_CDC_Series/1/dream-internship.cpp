#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll a;
    cin >> n >> a;
    ll s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s + n);
    ll ct = 0;
    int l = 0, r = n - 1;

    while (l < r)
    {
        while (s[l] * s[r] > a)
            r--;
        if (l < r)
        {
            ct += (r - l);
            l++;
        }
    }
    cout << ct;
}