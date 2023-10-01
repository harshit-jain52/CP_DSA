#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, n;
    cin >> x >> n;

    set<int> pos;
    multiset<int> gaps;
    pos.insert(0);
    pos.insert(x);
    gaps.insert(x);

    while (n--)
    {
        int p;
        cin >> p;

        auto it = pos.upper_bound(p);
        int r = *it, l = *(--it);
        gaps.erase(gaps.find(r - l));
        gaps.insert(r - p);
        gaps.insert(p - l);
        pos.insert(p);

        it = gaps.end();
        cout << *(--it) << " ";
    }
}