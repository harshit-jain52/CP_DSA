#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll withoutZeroes(ll n)
{
    string s = to_string(n);
    ll num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '0')
        {
            num = num * 10 + (int)(s[i] - '0');
        }
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;

    if (withoutZeroes(a) + withoutZeroes(b) == withoutZeroes(a + b))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}