#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 3e4 + 5;
const int INF = 1e7;

struct node
{
    int pref, tot;
    node() { pref = tot = -INF; }
};

string s;
node seg[4 * N];

node merge(node a, node b)
{
    node tmp;
    tmp.tot = a.tot + b.tot;
    tmp.pref = max(a.pref, a.tot + b.pref);
    return tmp;
}

void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        int dig = ((s[l] == '(') ? -1 : 1);
        seg[id].pref = seg[id].tot = dig;
        return;
    }

    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

void update(int id, int l, int r, int pos)
{
    if (l > r || l > pos || pos > r)
        return;
    if (l == r)
    {
        s[l] = (s[l] == '(') ? ')' : '(';
        int dig = (s[l] == '(') ? -1 : 1;
        seg[id].pref = seg[id].tot = dig;
        return;
    }

    int mid = (l + r) / 2;
    update(id << 1, l, mid, pos);
    update(id << 1 | 1, mid + 1, r, pos);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

void check()
{
    if (seg[1].tot == 0 && seg[1].pref <= 0)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

int main()
{
    FASTIO
    int n, t = 1;
    while (cin >> n)
    {
        cout << "Test " << t << ":\n";
        cin >> s;
        build(1, 0, n - 1);

        int m;
        cin >> m;
        while (m--)
        {
            int k;
            cin >> k;
            if (k == 0)
                check();
            else
                update(1, 0, n - 1, k - 1);
        }
        t++;
    }
}