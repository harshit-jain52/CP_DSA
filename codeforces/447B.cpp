#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    ll k, a[26], i;
    cin >> s >> k;

    for (i = 0; i < 26; i++)
    {
        cin >> a[i];
    }

    ll m = *max_element(a, a + 26);
    ll f = 0;

    for (i = 0; i < s.size(); i++)
    {
        f += (i + 1) * a[s[i] - 'a'];
    }
    for (; i < s.size() + k; i++)
    {
        f += (i + 1) * m;
    }

    cout << f;
}