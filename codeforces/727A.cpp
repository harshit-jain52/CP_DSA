#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
vector<vector<ll>> pos;

void generate(ll x, vector<ll> &v)
{
    v.push_back(x);
    if (x >= b)
    {
        pos.push_back(v);
        return;
    }

    generate(2 * x, v);
    v.pop_back();
    generate(10 * x + 1, v);
    v.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    vector<ll> v;
    int idx = 0;

    generate(a, v);
    bool isPossible = false;
    for (auto vec : pos)
    {
        idx++;
        if (vec[vec.size() - 1] == b)
        {
            isPossible = true;
            break;
        }
    }

    if (isPossible)
    {
        cout << "YES" << endl
             << pos[idx - 1].size() << endl;
        for (auto it : pos[idx - 1])
        {
            cout << it << " ";
        }
    }
    else
    {
        cout << "NO";
    }
}