#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, ll> ct;
    map<int, ll> prevct;
    set<int> pref;
    for (int i = 0; i < n; i++)
    {
        set<int> next;
        map<int, ll> nextct;
        for (int x : pref)
        {
            int OR = a[i] | x;
            next.insert(OR);
            nextct[OR] += prevct[x];
        }
        next.insert(a[i]);
        nextct[a[i]]++;
        pref = next;
        for (auto num : prevct)
            ct[num.first] += num.second;
        prevct = nextct;
    }

    while (q--)
    {
        int x;
        cin >> x;
        cout << ct[x] + prevct[x] << endl;
    }
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}