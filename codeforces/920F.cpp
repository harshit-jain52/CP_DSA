#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 1;
const int NMAX = 3e5 + 5;
vector<int> D(N, 1);

void divisors()
{
    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
            D[j]++;
}

struct node
{
    ll sum;
    bool done;
    node()
    {
        sum = 0;
        done = false;
    }
};

ll a[NMAX];
node seg[4 * NMAX];

node merge(node a, node b)
{
    node temp;
    temp.sum = a.sum + b.sum;
    temp.done = a.done && b.done;
    return temp;
}

void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        seg[id].sum = a[l];
        seg[id].done = (a[l] == 1 || a[l] == 2);
        return;
    }

    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

void update(int id, int l, int r, int lq, int rq)
{
    if (l > rq || lq > r || seg[id].done)
        return;
    if (l == r)
    {
        a[l] = D[a[l]];
        seg[id].sum = a[l];
        seg[id].done = (a[l] == 1 || a[l] == 2);
        return;
    }
    int mid = (l + r) / 2;
    update(id << 1, l, mid, lq, rq);
    update(id << 1 | 1, mid + 1, r, lq, rq);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

ll query(int id, int l, int r, int lq, int rq)
{
    if (l > rq || lq > r)
        return 0;

    if (lq <= l && rq >= r)
        return seg[id].sum;

    int mid = (l + r) / 2;
    return (query(id << 1, l, mid, lq, rq) + query(id << 1 | 1, mid + 1, r, lq, rq));
}

int main()
{
    FASTIO
    divisors();

    // auto countSteps = [&](int num)->int{
    //     int steps=1;
    //     while(D[num]>2){
    //         num = D[num];
    //         steps++;
    //     }
    //     return steps;
    // };

    // int lim=0;
    // for(int i=2;i<N;i++) lim=max(lim,countSteps(i));
    // cout << lim<<endl;
    // lim comes out to be 6 => D() decreases very fast

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);
    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            update(1, 0, n - 1, l - 1, r - 1);
        else
            cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
    }
}