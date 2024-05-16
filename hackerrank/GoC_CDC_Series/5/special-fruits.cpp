#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second

void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<ll, int>, int>> events;
    for (int i = 0; i < n; i++)
    {
        ll v, x;
        cin >> v >> x;
        events.push_back({{v - x, -1}, i});
        events.push_back({{v + x, 1}, i});
    }

    sort(events.begin(), events.end());
    vector<int> mark(n, n + 1);
    vector<ll> taken;
    int ct = 0;
    for (auto e : events)
    {
        // cout << e.F.F <<" "<<e.F.S<<" "<<e.S<<" "<<ct<<endl;
        if (e.F.S == -1)
            mark[e.S] = ct;
        else if (e.F.S == 1 && mark[e.S] < ct)
            continue;
        else
        {
            taken.push_back(e.F.F);
            ct++;
        }
    }

    cout << ct << endl;
    for (ll t : taken)
        cout << t << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t_;
    cin >> t_;
    while (t_--)
        solve();
}