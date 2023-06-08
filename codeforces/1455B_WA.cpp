#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x;

void jumps(ll y, ll ct, vector<ll> &v)
{

    if (y == x)
    {
        v.push_back(ct);
        return;
    }
    if (y > x)
    {
        v.push_back(ct + 1);
        return;
    }

    jumps(y + ct + 1, ct + 1, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> x;
        vector<ll> v;

        jumps(0, 0, v);
        jumps(-1, 1, v);

        cout << *min_element(v.begin(), v.end()) << endl;
    }
}